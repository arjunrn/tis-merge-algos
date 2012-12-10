#include "HashJoin.h"
#include "hashmap.h"
#include "Relation.h"
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
    Relation<Tuple> * longer_relation;
    
    shorter_relation = &relation2;
    longer_relation = &relation1;
    /*if(relation1.length() < relation2.length()){
        shorter_relation = &relation1;
        longer_relation = & relation2;
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
    }*/

    int largest_value = -1;
    for(int i=0 ; i < shorter_relation->length() ; i ++){
        if(shorter_relation->get(i) > largest_value){
            largest_value = shorter_relation->get(i);
        }
    }

    cout << endl << "The largest value is " << largest_value << endl;

    ValueNode ** nodell = new ValueNode*[largest_value + 1];
    for(int i=0 ; i < largest_value + 1 ; i++){
        nodell[i] = NULL;
    }

    cout << "Now Building the Linked List" << endl;

    for(int i = 0 ; i < shorter_relation->length() ; i++){
        unsigned key = shorter_relation->get(i);
        //cout << "Key is :" << key << endl;
        unsigned value = shorter_relation->getValue(i);
        //cout << "Value is :" << value << endl;
        
        ValueNode * node = new ValueNode(value);
        if(nodell[key] == NULL){
            //cout << "No value yet for key=" << key << endl;
            nodell[key] = node;
        }
        else{
            ValueNode * tempNode = nodell[key];
            while(tempNode->hasNext() != NULL){
                tempNode = tempNode->getNext();
            }
            //cout << "Value already exists for key=" << key << endl;
            tempNode->setNext(node);
        }
    }

    #ifdef DEBUG
    for(int i=0 ; i < largest_value + 1 ; i++){
        cout << i << " || ";
        if(nodell[i] == NULL) {
            cout << endl;
            continue;
        }
        ValueNode * tempNode = nodell[i];
        while(tempNode != NULL){
            cout << " -> " << tempNode->getValue();
            tempNode = tempNode->getNext();
        }
        cout << endl;
    }

    shorter_relation->print();
    #endif

    for(int i=0 ; i < longer_relation->length(); i++){
        unsigned key = longer_relation->get(i);
        unsigned value = longer_relation->getValue(i);
        
        #ifdef DEBUG
            //cout << "Key : " << key << endl;
            //cout << "Value : " << value << endl; 
        #endif
        
        if(key <= largest_value && nodell[key] != NULL){
            ValueNode * tempNode = nodell[key];
            do{
                unsigned tempValue = tempNode->getValue();
                Triple newTriple;
                newTriple.id = key;
                newTriple.value1 = value;
                newTriple.value2 = tempValue;
                output_relation.append(newTriple);
                tempNode = tempNode->getNext();
            }
            while(tempNode!= NULL);
        }
    }

}
