// Copyright (c) 2012 Benjamin Schlegel
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#define MAX_PRINT_TUPLES 10
#define MAX_OUTPUT_TUPLES 100000000

#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <sys/time.h>
#endif 

#include "Relation.h"
#include <iostream>
#include <cstdlib>

#ifdef NESTEDLOOPGROUP
#include "NestedLoopGroup.h"
#define GroupOperatorImpl NestedLoopGroup
#endif
#ifdef HASHGROUP
#include "HashGroup.h"
#define GroupOperatorImpl HashGroup
#endif
#ifdef SORTMERGEGROUP
#include "SortMergeGroup.h"
#define GroupOperatorImpl SortMergeGroup
#endif
#ifndef GroupOperatorImpl
#error "No group-operator implementation defined"
#endif

using namespace std;

double getTime_ms() {
#if defined(_MSC_VER)
	FILETIME start;
	GetSystemTimeAsFileTime(&start);
	ULONGLONG time = (((ULONGLONG) start.dwHighDateTime) << 32) + start.dwLowDateTime;
	return (double) time / 10000;
#else
	struct timeval starttime;
	gettimeofday(&starttime,0x0);
	return starttime.tv_sec * 1000 + starttime.tv_usec / 1000;
#endif
}

void generateRelation(Relation<Tuple> & relation, unsigned length, unsigned largest_value, unsigned factor) {
	for(int i = 0; i < length ; i++) {
		Tuple t;
		t.id = rand() % largest_value;
		t.value = t.id * factor;
		relation.append(t);
	}
}


int main(int argc, char * argv[]) {
	// check the number of parameter
	if(argc != 3) {
		cerr << "Usage: " << argv[0] << " <value domain> <relation length>" << endl;
		exit(0);
	}
	// parse the parameter
	unsigned value_domain = atoi(argv[1]);
	unsigned relation_length = atoi(argv[2]);
	
	// initialize the random number generator
	srand(1312);
	
	// create the input relations
	cout << "Generated the input relation..." << flush;
	Relation<Tuple> input_relation(relation_length);
	// generate the tuples
	generateRelation(input_relation,relation_length, value_domain,2);
	cout << "done" << endl;
	
	// get space for the output relations
	Relation<Tuple> output_relation(relation_length);
	
	// create the data structures for the join operator
	GroupOperatorImpl group_operator;
	
	// perform the join
	cout << "Perform the group operation..." << flush;
	double start_time = getTime_ms();
	group_operator.group_sum(input_relation,output_relation);
	double end_time = getTime_ms();
	cout << "done" << endl;
	
	// print some statistics and the first few join tuples
	cout << "The output relation has " << output_relation.length() << " tuples" << endl;
	cout << "The group operation required " << end_time - start_time << "ms to finish" << endl;
	unsigned print_tuples = MAX_PRINT_TUPLES > output_relation.length() ? output_relation.length() : MAX_PRINT_TUPLES;
	if(print_tuples != 0) {
		cout << "The first " << print_tuples << " tuple(s) are:" << endl;
		for(int i = 0 ; i < print_tuples ; i++) {
			Tuple t = output_relation[i];
			cout << "T" << i << " = { " << t.id << ", " << t.value << " }" << endl;
		}
	}

	return 0;
}
