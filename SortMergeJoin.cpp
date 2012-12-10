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

    unsigned rel1_len = sorted_relation1->length();
    unsigned rel2_len = sorted_relation2->length();
    unsigned rel1_counter = 0;
    unsigned rel2_counter = 0;

    while(rel1_counter < rel1_len && rel2_counter < rel2_len) {
        
        #ifdef DEBUG
        cout << "Rel1 Counter: " << rel1_counter << endl;
        cout << "Rel2 Counter: " << rel2_counter << endl;
        #endif

        if(sorted_relation1->get(rel1_counter) == sorted_relation2->get(rel2_counter)){
            unsigned temp_rel2_counter = rel2_counter;
            
            while(temp_rel2_counter < rel2_len && sorted_relation1->get(rel1_counter) == sorted_relation2->get(temp_rel2_counter)){
                
                #ifdef DEBUG
                cout << "Rel2 Temp Counter: " << temp_rel2_counter << endl;
                #endif 
                
                Triple newTriple;
                newTriple.id = sorted_relation1->get(rel1_counter);
                newTriple.value1 = sorted_relation1->getValue(rel1_counter);
                newTriple.value2 = sorted_relation2->getValue(temp_rel2_counter);
                output_relation.append(newTriple);
                #ifdef DEBUG
                cout << "Appended Triple" << endl;
                #endif
                temp_rel2_counter++;    
            }
            rel1_counter++;
            continue;
        }
        else if(sorted_relation1->get(rel1_counter) > sorted_relation2->get(rel2_counter)){
            rel2_counter++;
            continue;
        }
        else if(sorted_relation1->get(rel1_counter) < sorted_relation2->get(rel2_counter)){
            rel1_counter++;
            continue;
        }
        else{
            cout << "Catastrophic Logic Failure. Control Shouldn't Reach Here!!!";
        }
        
        #ifdef DEBUG
            cout << "Moving to Next Iteration" << endl;
        #endif
    }

}