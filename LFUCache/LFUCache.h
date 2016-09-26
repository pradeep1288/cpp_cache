//
// Created by Pradeep Nayak on 9/26/16.
//

#ifndef CPP_CACHE_LFUCACHE_H
#define CPP_CACHE_LFUCACHE_H

#include <map>
#include <vector>
#include <queue>
#include "../Cache.h"

template <class K, class V>
struct LFUCacheItem {
    K key;
    V value;
    int numHits;
};

template <class K, class V>
struct Comp {
    bool operator()(const LFUCacheItem<K,V>* a, const LFUCacheItem<K,V>* b) {
        return (a->numHits > b->numHits);
    }
};

template <class K, class V>
class LFUCache: Cache<K,V> {
private:
    std::map<K,LFUCacheItem<K,V>*> _cacheEntries;
    std::vector<LFUCacheItem<K,V>*> _freeEntries;
    LFUCacheItem<K,V>* _entries;
    std::priority_queue<LFUCacheItem<K,V>*, std::vector<LFUCacheItem<K,V>*>,Comp<K,V>> _lfuList;

public:
    LFUCache(size_t size) {
        _entries = new LFUCacheItem<K,V>[size];
        for (int i = 0; i<size; i++)
            _freeEntries.push_back(_entries+i);

    }

    virtual V get(K key) override {
        typename std::map<K,LFUCacheItem<K,V>*>::iterator it = _cacheEntries.find(key);
        if (it != _cacheEntries.end()) {
            it->second->numHits++;
            std::make_heap(const_cast<LFUCacheItem<K,V>**> (&_lfuList.top()), const_cast<LFUCacheItem<K,V>**> ((&_lfuList.top()) + _lfuList.size()), Comp<K,V>());
            return it->second->value;
        }
        return (V) NULL;
    }

    virtual void put(K key, V value) override {
        typename std::map<K,LFUCacheItem<K,V>*>::iterator it = _cacheEntries.find(key);
        if (it != _cacheEntries.end()) {
            it->second->value = value;
            it->second->numHits++;
            std::make_heap(const_cast<LFUCacheItem<K,V>**> (&_lfuList.top()), const_cast<LFUCacheItem<K,V>**> ((&_lfuList.top()) + _lfuList.size()), Comp<K,V>());
        } else {
            LFUCacheItem<K,V>* entry = NULL;
            if (_freeEntries.empty()) {
                entry = _lfuList.top();
                _lfuList.pop();

            } else {
                entry = _freeEntries.back();
                _freeEntries.pop_back();
                _cacheEntries[key] = entry;
            }
            entry->key = key;
            entry->value = value;
            entry->numHits = 1;
            _lfuList.push(entry);
        }
    }

    virtual void remove(K key) override {
        return;
    }
};
#endif //CPP_CACHE_LFUCACHE_H
