#pragma once
template <typename K, typename V>
class Dictionary {
public:
    virtual ~Dictionary() {}

    virtual bool insert(const K& key, const V& value) = 0;
    virtual bool erase(const K& key) = 0;
    virtual bool find(const K& key, V& outValue) const = 0;
    virtual bool update(const K& key, const V& newValue) = 0;
    virtual int  size() const = 0;
};