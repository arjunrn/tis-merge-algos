#ifndef HASHJOIN_H
#define HASHJOIN_H

#include "JoinOperator.h"

class HashJoin : public JoinOperator {
private:
	//
	// put your private member variables and function here
	//
public:
	/** @short the default constructor */
	HashJoin();
	
	/** @short the default destructor */
	~HashJoin();
	
	/** 
	* @short perform the join on the two input relations
	*/
	void process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation);
};

#endif // HASHJOIN_H
