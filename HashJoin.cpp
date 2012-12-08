#include "HashJoin.h"
#include "hashmap.h"
#define DEBUG true

HashJoin::HashJoin() {
	//
	// put your class initialization code here
	//
}

HashJoin::~HashJoin() {
	//
	// put your class de-initialization code here
	//
}

void HashJoin::process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation) {
	Relation<Tuple> * shorter_relation;
    if(relation1.length() < relation2.length()){
        shorter_relation = &relation1;
        #ifdef DEBUG
        cout << endl << "Relation 1 is the shorter relation." << endl;
        #endif
    }
    else{
        shorter_relation = & relation2;
        #ifdef DEBUG
        cout << endl << "Relation 2 is the shorter relation." << endl;
        #endif
    }

    int largest_value = -1;
    for(int i=0 ; i < shorter_relation->length() ; i ++){
        if(shorter_relation->get(i) > largest_value){
            largest_value = shorter_relation->get(i);
        }
    }

    cout << endl << "The largest value is " << largest_value << endl;

    //ValueNode ** nodell = new ValueNode*[largest_value];

}
