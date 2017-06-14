#include "entryList.h"


entryList::entryList(){
    root = 0;
    size = 0;
}


int entryList::getHead(){
    int retVal = -1;
    if(root != 0){
        retVal = root->matricula;
        entryNode* ptr = root;
        root = root->getNext();
        delete ptr;
    }
    size -= 1;
    return retVal;
}

void entryList::addEntry(int matr){
    entryNode* ptr = new entryNode(matr);
    ptr->setNext(root);
    root = ptr;
    size += 1;
}
