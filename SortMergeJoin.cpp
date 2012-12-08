#include "SortMergeJoin.h"
#include <iostream>
#define DEBUG true

using namespace std;

void sort_relation(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation){
    
}


SortMergeJoin::SortMergeJoin() {
	//
	// put your class initialization code here
	//
}

SortMergeJoin::~SortMergeJoin() {
	//
	// put your class de-initialization code here
	//
}

void SortMergeJoin::process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation) {
	Relation<Tuple> * sorted_relation1;
    Relation<Tuple> * sorted_relation2;

    sorted_relation1 = relation1.getSorted();
    sorted_relation2 = relation2.getSorted();


    #ifdef DEBUG
    sorted_relation1->print();
    sorted_relation2->print();
    cout << endl << "Length of Relation 1 is : " << sorted_relation1->length() << endl;
    cout << "Length of Relation 2 is : " << sorted_relation2->length() << endl;
    #endif
}