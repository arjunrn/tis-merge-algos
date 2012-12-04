// Copyright (c) 2012 Benjamin Schlegel
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef NESTEDLOOPJOIN_H
#define NESTEDLOOPJOIN_H

#include "JoinOperator.h"

class NestedLoopJoin : public JoinOperator {
private:
public:
	/** the default constructor */
	NestedLoopJoin();
	
	/** the default destructor */
	~NestedLoopJoin();
	
	/** 
		* @short perform the join on the two input relations
		*/
	void process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation);
};

#endif // NESTEDLOOPJOIN_H