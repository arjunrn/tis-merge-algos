#ifndef HASHGROUP_H
#define HASHGROUP_H

#include "GroupOperator.h"

class HashGroup : public GroupOperator {
private:
	//
	// put your private member variables and function here
	//
public:
	/** the default constructor */
	HashGroup();
	
	/** the default destructor */
	~HashGroup();
	
	/** @short perform the group sum operation */
	void group_sum(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation);
};

#endif // HASHGROUP_H
