#include <iostream>
#include "LRUCache.h"

using namespace std;

int main() {
    LRUCache<int,int> *_intCache = new LRUCache<int,int>(5);
    _intCache->put(1,1);
    _intCache->put(2,2);
    _intCache->put(3,2);
    _intCache->put(4,2);
    _intCache->put(5,2);
    _intCache->put(6,2);
    cout<< "Cache entry: " << _intCache->get(1)<< endl;
    return 0;
}