#ifndef SORTMERGEGROUP_H
#define SORTMERGEGROUP_H

#include "GroupOperator.h"

class SortMergeGroup : public GroupOperator {
private:
	//
	// put your private member variables and function here
	//
public:
	/** the default constructor */
	SortMergeGroup();
	
	/** the default destructor */
	~SortMergeGroup();
	
	/** @short perform the group sum operation */
	void group_sum(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation);
};

#endif // SORTMERGEGROUP_H
