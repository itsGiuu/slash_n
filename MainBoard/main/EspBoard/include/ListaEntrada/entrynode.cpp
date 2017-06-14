#include "entryNode.h"

entryNode::entryNode(int matr)
{
    matricula = matr;
    nextNode = 0;

}


entryNode* entryNode::getNext(){
    return nextNode;
}

void entryNode::setNext(entryNode *next){
    nextNode = next;
}


