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

#ifndef RELATION_H
#define RELATION_H

#include <cassert>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "debug.h"

using namespace std;

typedef struct Tuple {
unsigned id;
unsigned value;
} Tuple;

typedef struct Triple {
unsigned id;
unsigned value1;
unsigned value2;
} Triple;

template <class Row>
class Relation {
private:
	/// holds the maximum length of the relation
	unsigned mMaxLength;
	/// holds the length of the relation
	unsigned mLength;
	/// holds the tuples of the relation
	Row * mpRows;
public:
	/** @short the default constructor */
	Relation(unsigned max_length);
	Relation(unsigned max_legnth, Row* rows, unsigned len);
	
	/** @short the default destructor */
	~Relation();
	
	/** @return the 'i'-th tuple of the relation */
	Row & operator[](unsigned i);
	int get(unsigned i);
	int getValue(unsigned i);
	/** 
	 * @short appends a tuple at the end of the relation 
	 * @return true if the operation was successful
	 */
	bool append(Row & row);
	
	/** @return the length of the relation */
	unsigned length() const;

	static int rowCompare(const void* a, const void* b){
	    Row rowA = *((Row*)a);
	    Row rowB = *((Row*)b);

	    if (rowA.id < rowB.id)
	        return -1;
	    if (rowA.id == rowB.id)
	        return 0;
	    return 1;
	}
    
    Relation<Row>* getSorted();
	void print();

};

template <class Row>
Relation<Row>::Relation(unsigned max_length) : mMaxLength(max_length) {
	mpRows = new Row[max_length];
	mLength = 0;
}

template <class Row>
Relation<Row>::Relation(unsigned max_length,Row* rows, unsigned len) : mMaxLength(max_length) {
	mpRows = rows;
	mLength = len;
}


template <class Row>
Relation<Row>::~Relation() {
	#ifdef DEBUG
	cout << "Calling destructor for " << mpRows << endl;
	#endif
	delete[] mpRows;
}

template <class Row>
Row & Relation<Row>::operator[](unsigned i) {
	assert(i < mLength);
	return mpRows[i];
}

template <class Row>
int Relation<Row>::get(unsigned i){
    assert(i < mLength);
    return mpRows[i].id;
}

template<class Row>
int Relation<Row>::getValue(unsigned i){
	assert(i < mLength);
	return mpRows[i].value;
}

template <class Row>
unsigned Relation<Row>::length() const {
	return mLength;
}

template <class Row>
bool Relation<Row>::append(Row & row) {
	if(mLength < mMaxLength) {
		memcpy(&mpRows[mLength],&row,sizeof(Row));
		mLength++;
		return true;
	}
	else {
		return false;
	}
}


template<class Row>
Relation<Row>* Relation<Row>::getSorted(){
    Row* dup_mpRows = new Row[mMaxLength];
    
    #ifdef DEBUG
    cout << endl << "Address is " << dup_mpRows << endl;
    cout << "Now copying the Rows" << endl;
    #endif

    for(int i=0 ; i < mLength ; i++){
        memcpy(&dup_mpRows[i],&mpRows[i],sizeof(Row));
    }
    
    #ifdef DEBUG
    cout << endl << "Done copying the Rows";
    #endif

    std::qsort(dup_mpRows, mMaxLength, sizeof(Row),rowCompare );
    
    #ifdef DEBUG
    cout << endl << "Done sorting the Rows";
    #endif

    return new Relation<Row>(mMaxLength, dup_mpRows, mLength);
    /*
    #ifdef DEBUG
    cout << endl << "Done instantiating the new Sorted Relation : " << sortedRelation;
    #endif

    #ifdef DEBUG
    cout << endl << "Sorted Relation has the address : " << sortedRelation;
    #endif*/
}

template<class Row>
void Relation<Row>::print(){
	for(int i=0 ; i < mLength ; i++){
    	cout << mpRows[i].id << " " << mpRows[i].value << endl ;
    }
}

#endif
