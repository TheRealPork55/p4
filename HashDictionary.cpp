#pragma once
#include "HashDictionary.h"

template <typename K, typename V>
HashDictionary<K, V>::HashDictionary() : numEntries(0) {
    table.resize(11);
}

template <typename K, typename V>
int HashDictionary<K, V>::hashKey(const K& key) const {
    std::hash<K> h;
    return h(key) % table.size();
}

template <typename K, typename V>
bool HashDictionary<K, V>::insert(const K& key, const V& value) {
    int idx = hashKey(key);
    for (auto& entry : table[idx]) {
        if (entry.key == key) {
            entry.value = value;
            return true;
        }
    }
    table[idx].push_back({key, value});
    numEntries++;

    if ((double)numEntries / table.size() > LOAD_FACTOR)
        rehash();

    return true;
}

template <typename K, typename V>
bool HashDictionary<K, V>::erase(const K& key) {
    int idx = hashKey(key);
    auto& chain = table[idx];

    for (auto it = chain.begin(); it != chain.end(); ++it) {
        if (it->key == key) {
            chain.erase(it);
            numEntries--;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
bool HashDictionary<K, V>::find(const K& key, V& outValue) const {
    int idx = hashKey(key);
    for (const auto& entry : table[idx]) {
        if (entry.key == key) {
            outValue = entry.value;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
bool HashDictionary<K, V>::update(const K& key, const V& newValue) {
    int idx = hashKey(key);
    for (auto& entry : table[idx]) {
        if (entry.key == key) {
            entry.value = newValue;
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
int HashDictionary<K, V>::size() const {
    return numEntries;
}

template <typename K, typename V>
void HashDictionary<K, V>::rehash() {
    std::vector<std::list<Entry>> old = table;
    table.clear();
    table.resize(old.size() * 2 + 1);
    numEntries = 0;

    for (auto& chain : old) {
        for (auto& entry : chain) {
            insert(entry.key, entry.value);
        }
    }
}

template <typename K, typename V>
std::vector<V*> HashDictionary<K, V>::getAllEntries() {
    std::vector<V*> all;
    for (auto& chain : table) {
        for (auto& entry : chain) {
            all.push_back(&entry.value);
        }
    }
    return all;
}
