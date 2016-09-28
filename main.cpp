#include <iostream>
#include "LRUCache/LRUCache.h"
#include "LFUCache/LFUCache.h"
#include <cassert>

using namespace std;


void testOneSizeLRUCache() {
    cout<<"BEGIN "<<__FUNCTION__<<" tests"<<endl;
    LRUCache<int, int> *oneEntry = new LRUCache<int, int>(1);
    for (int i; i<10000;i++) {
        oneEntry->put(i,i+1);
    }
    assert(oneEntry->get(9999) == 10000);
    cout<<"END "<<__FUNCTION__<<" tests"<<endl;
}

void testOneSizeLFUCache() {
    cout<<"BEGIN "<<__FUNCTION__<<" tests"<<endl;
    LFUCache<int, int> *oneEntry = new LFUCache<int, int>(1);
    for (int i; i<10000;i++) {
        oneEntry->put(i,i+1);
    }
    assert(oneEntry->get(9999) == 10000);
    cout<<"END "<<__FUNCTION__<<" tests"<<endl;
}

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
    cout<<"BEGIN " << __FUNCTION__<<" tests"<<endl;
    LFUCache<int,int> *fiveEntries = new LFUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=0;i<5;i++) {
        assert(fiveEntries->get(i) == i + 1);
    }
    cout<<"END: "<<__FUNCTION__<<" tests"<<endl;
}

void testLFUPutsAndEviction() {
    cout<<"BEGIN " << __FUNCTION__<<" tests"<<endl;
    LFUCache<int,int> *fiveEntries = new LFUCache<int,int>(5);
    for (int i=0;i<5;i++)
        fiveEntries->put(i,i+1);
    for (int i=1;i<5;i++) {
        assert(fiveEntries->get(i) == i+1);
        assert(fiveEntries->get(i) == i+1);
    }

    fiveEntries->put(8,9);
    assert(fiveEntries->get(8) == 9);
    assert(fiveEntries->get(0) == 0);
    cout<<"END: "<<__FUNCTION__<<" tests"<<endl;
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
    testLFUPutsAndEviction();
    testOneSizeLRUCache();
    testOneSizeLFUCache();
    return 0;
}