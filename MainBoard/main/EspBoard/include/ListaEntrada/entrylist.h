#ifndef ENTRYLIST_H
#define ENTRYLIST_H

#include "entryNode.cpp"

class entryList{
    private:
        entryNode* root;
    public:
        int size;
        entryList();
        int getHead();
        void addEntry(int matr);

};

#endif // ENTRYLIST_H
