#include <iostream>
#include "LRUCache.h"

using namespace std;

int main() {
    LRUCache<int,int> *_intCache = new LRUCache<int,int>(5);
    _intCache->put(1,1);
    _intCache->put(1,2);
    std::cout<< "here: " << _intCache->get(1)<< std::endl;
    return 0;
}