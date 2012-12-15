#include "HashGroup.h"
#include "hashmap.h"
#define HASH_MAP_SIZE 10


HashGroup::HashGroup() {
	//
	// put your class initialization code here
	//
}

HashGroup::~HashGroup() {
	//
	// put your class de-initialization code here
	//
}

void HashGroup::group_sum(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation) {
	
	Relation<Tuple> * shorter_relation = & input_relation;

	
    for(int i=0 ; i < shorter_relation->length() ; i ++){
        
    }

    HashMap * relMap = new HashMap(HASH_MAP_SIZE);

    unsigned largest_value = 0;
    for(int i = 0 ; i < shorter_relation->length() ; i++){
        unsigned key = shorter_relation->get(i);
        //cout << "Key is :" << key << endl;
        unsigned value = shorter_relation->getValue(i);
        //cout << "Value is :" << value << endl;
        relMap->putPair(key, value);

        if(shorter_relation->get(i) > largest_value){
            largest_value = shorter_relation->get(i);
        }
    }

    #ifdef DEBUG
    cout << endl << "The largest value is " << largest_value << endl;
    #endif
    
    for(int i=0 ; i <= largest_value ; i++){
    	ValueNode * returnList = relMap->getValues(i);
        if(returnList != NULL){
    		unsigned value_sum = 0;
    		ValueNode * tempNode = returnList;
    		while(tempNode != NULL){
    			value_sum += tempNode->getValue();
    			tempNode = tempNode->getNext();
    		}
    		Tuple newTuple;
    		newTuple.id = i;
    		newTuple.value = value_sum;
    		output_relation.append(newTuple);
    	}
    }
}
