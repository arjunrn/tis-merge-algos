#ifndef SORTMERGEJOIN_H
#define SORTMERGEJOIN_H

#include "JoinOperator.h"

class SortMergeJoin : public JoinOperator {
private:
	//
	// put your private member variables and function here
	//
public:
	/** @short the default constructor */
	SortMergeJoin();
	
	/** @short the default destructor */
	~SortMergeJoin();
	
	/** 
	* @short perform the join on the two input relations
	*/
	void process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation);
    
    static void* startSort1(void* rel){
        cout << "In Sort Function 1: " << endl;
        Relation<Tuple> * relation = (Relation<Tuple>*)rel;
        return relation->getSorted();
    }

    static void* startSort2(void* rel){
        cout << "In Sort Function 2: " << endl;
        Relation<Tuple> * relation = (Relation<Tuple>*)rel;
        return relation->getSorted();
    }

};

#endif // SORTMERGEJOIN_H
