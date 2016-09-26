#include <iostream>
#include "LRUCache/LRUCache.h"
#include "LFUCache/LFUCache.h"
#include <cassert>

using namespace std;


void testLRUPutsAndGets() {
    cout<<"BEGIN "<< __FUNCTION__<< " tests"<<endl;
    LRUCache<int,int> *fiveEntries = new LRUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++)
        assert(fiveEntries->get(i) == i+1);
    cout<<"END "<< __FUNCTION__ <<" tests"<<endl;
}

void testLFUPutsAndGets() {
    cout<<"Begin " << __FUNCTION__<<" tests"<<endl;
    LFUCache<int,int> *fiveEntries = new LFUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++) {
        cout<<"Get "<<i<<" is "<< fiveEntries->get(i)<<endl;
        //assert(fiveEntries->get(i) == i + 1);
    }
    cout<<"End: "<<__FUNCTION__<<" tests"<<endl;
}


void testLRUPutAndRemove() {
    cout<<"BEGIN "<< __FUNCTION__<< " tests"<<endl;
    LRUCache<int,int> *fiveEntries = new LRUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++)
        fiveEntries->remove(i);

    for (int i=0;i<5;i++) {
        assert(fiveEntries->get(i) == (int) NULL);
    }
    cout<<"END "<< __FUNCTION__ <<" tests"<<endl;
}

int main() {
    testLRUPutsAndGets();
    testLRUPutAndRemove();
    testLFUPutsAndGets();
    return 0;
}