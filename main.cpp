#include <iostream>
#include "LRUCache/LRUCache.h"
#include <cassert>

using namespace std;


void testPutsAndGets() {
    cout<<"Begin testPutsAngGets tests"<<endl;
    LRUCache<int,int> *fiveEntries = new LRUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++)
        assert(fiveEntries->get(i) == i+1);
    cout<<"End testPutsAngGets tests"<<endl;
}

void testPutAndRemove() {
    cout<<"Begin "<<__FUNCTION__<< " test" <<endl;
    LRUCache<int,int> *fiveEntries = new LRUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++)
        fiveEntries->remove(i);

    for (int i=0;i<5;i++) {
        assert(fiveEntries->get(i) == (int) NULL);
    }
}

int main() {
    testPutsAndGets();
    testPutAndRemove();
    return 0;
}