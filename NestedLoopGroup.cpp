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

#include "NestedLoopGroup.h"

NestedLoopGroup::NestedLoopGroup() {
}

NestedLoopGroup::~NestedLoopGroup() {
}

void NestedLoopGroup::group_sum(Relation<Tuple> & input_relation, Relation<Tuple> & output_relation) {
	for(int i = 0 ; i < input_relation.length() ; i++) {
		Tuple t = input_relation[i];
		// search the group within the output relation
		unsigned j = 0;
		while(j < output_relation.length()) {
			if(t.id == output_relation[j].id) {
				break;
			}
			j++;
		}
		if(j == output_relation.length()) {
			// the group is not available -> create a new one
			output_relation.append(t);
		}
		else {
			// append the value to the group
			output_relation[j].value += t.value;
		}
	}
}
