//
// Created by Pradeep Nayak on 9/26/16.
//

#ifndef CPP_CACHE_CACHE_H
#define CPP_CACHE_CACHE_H

template <class K, class V>
class Cache {
public:
    virtual V get(K key) = 0;
    virtual void put (K key, V val) = 0;
    virtual void remove(K key) = 0;
};

#endif //CPP_CACHE_CACHE_H
