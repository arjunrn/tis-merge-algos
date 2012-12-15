#include "HashJoin.h"
#include "hashmap.h"
#include "Relation.h"
#include "debug.h"
#define HASH_MAP_SIZE 10



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
    Relation<Tuple> * longer_relation;
    bool rel1_shorter = false;

    if(relation1.length() < relation2.length()){
        shorter_relation = &relation1;
        longer_relation = & relation2;
        rel1_shorter = true;
        #ifdef DEBUG
        cout << endl << "Relation 1 is the shorter relation." << endl;
        #endif
    }
    else{
        shorter_relation = & relation2;
        longer_relation = & relation1;
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

    HashMap * joinMap = new HashMap(HASH_MAP_SIZE);

    #ifdef DEBUG
    cout << endl << "The largest value is " << largest_value << endl;
    cout << "Now Building the Linked List" << endl;
    #endif


    for(int i = 0 ; i < shorter_relation->length() ; i++){
        unsigned key = shorter_relation->get(i);
        //cout << "Key is :" << key << endl;
        unsigned value = shorter_relation->getValue(i);
        //cout << "Value is :" << value << endl;
        
        joinMap->putPair(key, value);
    }

    #ifdef DEBUG
    joinMap->print();
    shorter_relation->print();
    cout << "Now Starting the Join Process...." << endl;
    #endif

    

    for(int i=0 ; i < longer_relation->length(); i++){
        unsigned key = longer_relation->get(i);
        unsigned value = longer_relation->getValue(i);
        #ifdef DEBUG
            cout << "Key : " << key << endl;
            cout << "Value : " << value << endl; 
        #endif
        ValueNode * resultList = joinMap->getValues(key);
        while(resultList != NULL){
            unsigned tempValue = resultList->getValue();
            Triple newTriple;

            newTriple.id = key;
            if(rel1_shorter){
                newTriple.value1 = tempValue;
                newTriple.value2 = value;
            }
            else{
                newTriple.value1 = value;
                newTriple.value2 = tempValue;
            }
            output_relation.append(newTriple);
            ValueNode * delPointer = resultList;
            resultList = resultList->getNext();
            delete delPointer;
        }
    }

}
