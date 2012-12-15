#ifndef HASHJOIN_H
#define HASHJOIN_H
#include <"hashmap.h">
#include "debug.h"

ValueNode::ValueNode(unsigned v){
    value = v;
    next = NULL;
}

unsigned ValueNode::getValue(){
    return value;
}

bool ValueNode::hasNext(){
    if(next != NULL){
        return true;
    }
    else{
        return false;
    }
}


#endif