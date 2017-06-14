#ifndef ENTRYNODE_H
#define ENTRYNODE_H

class entryNode;

class entryNode
{
private:
    entryNode* nextNode;
public:
    int matricula;
    entryNode(int matr);
    entryNode* getNext();
    void setNext(entryNode* next);
};

#endif // ENTRYNODE_H
