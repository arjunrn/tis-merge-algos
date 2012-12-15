class ValueNode{
private:
    unsigned key;
    unsigned value;
    ValueNode * next;

public:
    ValueNode(unsigned k, unsigned v){
        key = k;
        value = v;
        next = NULL;
    }

    unsigned getValue(){
        return value;
    }

    unsigned getKey(){
        return key;
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

class HashMap{
    unsigned hashLenght;
    ValueNode ** nodell;
    public:
        HashMap(unsigned len){
            hashLenght = len;
            nodell = new ValueNode*[hashLenght];
        }

        ~HashMap(){
            for(int i=0 ; i < hashLenght ; i++){
                ValueNode * destPointer = nodell[i];
                if(destPointer != NULL){
                    do{
                        ValueNode * tempPointer = destPointer;
                        destPointer = destPointer->getNext();
                        delete tempPointer;
                    }  
                    while(destPointer != NULL);  
                }
                
            }
        }

        bool putPair(unsigned key,unsigned value){
            unsigned position = key % hashLenght;
            if(nodell[position] == NULL){
                nodell[position] = new ValueNode(key, value);
            }
            else{
                ValueNode * lastPointerNode = nodell[position];
                while(lastPointerNode->hasNext() == true){
                    lastPointerNode = lastPointerNode->getNext();
                }
                lastPointerNode->setNext(new ValueNode(key, value));
            }
            return true;
        }

        ValueNode* getValues(unsigned key){
            unsigned position = key % hashLenght;
            ValueNode* returnList = NULL;
            ValueNode* returnListEndPointer = NULL;
            ValueNode* iterPointer = nodell[position];
            while(iterPointer != NULL){
                if(iterPointer->getKey() == key){
                    if(returnListEndPointer == NULL){
                        returnList = new ValueNode(key, iterPointer->getValue());
                        returnListEndPointer = returnList;
                    }
                    else{
                        ValueNode* newReturnNode = new ValueNode(key, iterPointer->getValue());
                        returnListEndPointer->setNext(newReturnNode);
                        returnListEndPointer = newReturnNode;
                    }
                }
                iterPointer = iterPointer->getNext();
            }
            return returnList;
        }

        void print(){
            for(int i=0; i < hashLenght ; i++){
                cout << i << " | ";
                ValueNode * printPointer = nodell[i];
                while(printPointer != NULL){
                    cout << printPointer->getKey() << "-" << printPointer->getValue() << "  ";
                    printPointer = printPointer->getNext();
                }
                cout << endl;
            }
        }

};
