#include "SortMergeJoin.h"

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
	Relation<Tuple> sorted_relation1(relation1.length());
    Relation<Tuple> sorted_relation2(relation2.length());

    sorted_relation1 = relation1.getSorted();

}