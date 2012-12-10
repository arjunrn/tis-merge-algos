#include "SortMergeGroup.h"

SortMergeGroup::SortMergeGroup() {
	//
	// put your class initialization code here
	//
}

SortMergeGroup::~SortMergeGroup() {
	//
	// put your class de-initialization code here
	//
}

void SortMergeGroup::group_sum(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation) {
	Relation<Tuple> * sorted_relation = input_relation.getSorted();
	unsigned rel_counter = 0;
	unsigned rel_length =  sorted_relation->length();
	while(rel_counter < rel_length){
		unsigned temp_counter = 0;
		unsigned value_sum = sorted_relation->getValue(rel_counter);
		while( (rel_counter + temp_counter + 1) < rel_length &&
			sorted_relation->get(rel_counter + temp_counter + 1) == sorted_relation->get(rel_counter)){
			value_sum += sorted_relation->getValue(rel_counter + temp_counter + 1);
			temp_counter++;
		}
		
		Tuple newTuple;
		newTuple.id = sorted_relation->get(rel_counter);
		newTuple.value = value_sum;
		output_relation.append(newTuple);
		rel_counter = rel_counter + temp_counter + 1; 
	}
}
