#include "HashGroup.h"
#include "hashmap.h"

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

	int largest_value = 0;
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

    for(int i=0 ; i <= largest_value ; i++){
    	if(nodell[i] != NULL){
    		unsigned value_sum = 0;
    		ValueNode * tempNode = nodell[i];
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
