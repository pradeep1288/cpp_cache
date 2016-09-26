//
// Created by Pradeep Nayak on 9/26/16.
//

#ifndef CPP_CACHE_MRUCACHE_H
#define CPP_CACHE_MRUCACHE_H

#include "../Cache.h"

template <class K, class V>
class MRUCache: public Cache<K,V> {
public:
    virtual V get(K key) override {
        return nullptr;
    }

    virtual void put(K key, V val) override {

    }

    virtual void remove(K key) override {

    }
};
#endif //CPP_CACHE_MRUCACHE_H
