//
// Created by Pradeep Nayak on 9/25/16.
//

#ifndef CPP_CACHE_LRUCACHE_H
#define CPP_CACHE_LRUCACHE_H

#include <map>
#include <vector>
#include "../Cache.h"

template <class K, class V>
struct LRUCacheItem {
    K key;
    V val;
    struct LRUCacheItem* next;
    struct LRUCacheItem* prev;
};

template <class K, class V>
class LRUCache : Cache<K,V>{
private:
    std::map<K, LRUCacheItem<K,V>*> _cacheEntries;
    LRUCacheItem<K,V>* _head;
    LRUCacheItem<K,V>* _tail;
    std::vector<LRUCacheItem<K,V>*> _freeEntries;
    LRUCacheItem<K,V>* _entries;

    void attach(LRUCacheItem<K,V> *node) {
        node->next = _head->next;
        _head->next = node;
        node->prev = _head;
        node->next->prev = node;
    }
    void detach(LRUCacheItem<K,V> *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(size_t size) {
        _entries = new LRUCacheItem<K,V>[size];
        for (int i=0;i<size;i++)
            _freeEntries.push_back(_entries+i);
        _head = new LRUCacheItem<K,V>;
        _tail = new LRUCacheItem<K,V>;
        _head->next = _tail;
        _head->prev = NULL;
        _tail->prev = _head;
        _tail->next = NULL;
    }

    ~LRUCache() {
        delete _head;
        delete _tail;
        delete[] _entries;
    }

    V get(K key) {
        typename std::map<K, LRUCacheItem<K,V>*>::iterator it = _cacheEntries.find(key);
        if (it != _cacheEntries.end()) {
            LRUCacheItem<K,V> *entry = _cacheEntries[key];
            detach(entry);
            attach(entry);
            return _cacheEntries[key]->val;
        }
        return (V) NULL;
    }

    void put(K key, V value) {
        typename std::map<K, LRUCacheItem<K,V>*>::iterator it = _cacheEntries.find(key);
        if (it != _cacheEntries.end()) {
            LRUCacheItem<K,V> *entry = _cacheEntries[key];
            detach(entry);
            entry->val = value;
            attach(entry);
        }
        else {
            if (_freeEntries.empty()) {
                LRUCacheItem<K,V> *node = _tail->prev;
                detach(node);
                _cacheEntries.erase(key);
                node->key = key;
                node->val = value;
                _cacheEntries[key] = node;
                attach(node);
            } else {
                LRUCacheItem<K,V> *node = _freeEntries.back();
                _freeEntries.pop_back();
                node->key = key;
                node->val = value;
                _cacheEntries[key] = node;
                attach(node);
            }
        }
    }

    void remove(K key) {
        typename std::map<K, LRUCacheItem<K,V>*>::iterator it = _cacheEntries.find(key);
        if (it != _cacheEntries.end()) {
            LRUCacheItem<K,V> *entry = it->second;
            detach(entry);
            entry->next = NULL;
            entry->prev = NULL;
            _freeEntries.push_back(entry);
            _cacheEntries.erase(key);
        }
        return;
    }
};


#endif //CPP_CACHE_LRUCACHE_H
