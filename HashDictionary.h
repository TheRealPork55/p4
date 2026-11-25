#pragma once
#include <vector>
#include <list>
#include <functional>
#include <string>
#include "Dictionary.h"
#include "WordInfo.h"

template <typename K, typename V>
class HashDictionary : public Dictionary<K, V> {
public:
    struct Entry {
        K key;
        V value;
    };

    HashDictionary();
    bool insert(const K& key, const V& value) override;
    bool erase(const K& key) override;
    bool find(const K& key, V& outValue) const override;
    bool update(const K& key, const V& newValue) override;
    int  size() const override;

    std::vector<V*> getAllEntries();

private:
    std::vector<std::list<Entry>> table;
    int numEntries;

    static constexpr double LOAD_FACTOR = 0.75;

    int hashKey(const K& key) const;
    void rehash();
};

#include "HashDictionary.cpp"
