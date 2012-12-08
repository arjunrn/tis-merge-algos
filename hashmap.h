

class ValueNode{
    unsigned value;
    ValueNode * next;

    ValueNode(unsigned v){
        value = v;
        next = NULL;
    }

    unsigned getValue(){
        return value;
    }

    bool hasNext(){
        if(next != NULL){
            return true;
        }
        else{
            return false;
        }
    }

}