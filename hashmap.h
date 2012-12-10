

class ValueNode{
private:
    unsigned value;
    ValueNode * next;

public:
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

    void setNext(ValueNode * n){
        next = n;
    }

    ValueNode * getNext(){
        return next;
    }

};