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

#include "NestedLoopJoin.h"

NestedLoopJoin::NestedLoopJoin() {
}

NestedLoopJoin::~NestedLoopJoin() {
}

void NestedLoopJoin::process(Relation<Tuple> & relation1, Relation<Tuple> & relation2, Relation<Triple> & output_relation) {
	for( unsigned i1 = 0 ; i1 < relation1.length() ; i1++ ) {
		for( unsigned i2 = 0 ; i2 < relation2.length() ; i2++) {
			// append each found join tuple to the 
			// output relation
			if(relation1[ i1 ].id == relation2[ i2 ].id) {
				Triple t;
				t.id = relation1[ i1 ].id;
				t.value1 = relation1[ i1 ].value;
				t.value2 = relation2[ i2 ].value;
				output_relation.append(t);
			}
		}
	}
}
