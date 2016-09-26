#include <iostream>
#include "LRUCache.h"
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

int main() {
    testPutsAndGets();
    return 0;
}