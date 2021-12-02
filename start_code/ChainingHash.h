/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    vector<list<pair<K, V>>> table;
    int tableSize = 0;
    float loadFactor = 0.75;

public:
    ChainingHash(int n = 11) {
        this->tableSize = n;
        for (int i = 0; i < tableSize; i++) {
            pair<K, V> newPair;
            list<pair<K, V>> newList;
            newList.push_back(newPair);
            table.push_back(newList);
        }
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return this->tableSize;
    }

    V operator[](const K& key) {
        for (pair<K, V> n : table[key]) {
            return n.second;
        }
    }

    bool insert(const std::pair<K, V>& pair) {
        list<std::pair<K, V>> newHash;
        newHash.push_back(pair);
        table[pair.first] = newHash;
        // Re-hashing

        // Determine load factor
        loadFactor = (float)bucket_count() / (float)tableSize;

        // Resize table to next prime number
        if (loadFactor > 0.75) {
            tableSize = findNextPrime(tableSize + 1);

            vector<std::list<std::pair<K, V>>> temp(tableSize);
            for (int i = 0; i < table.size(); i++) {
                temp[i] = table[i];
            }
            table = temp;

            // Set new load factor
            loadFactor = (float)bucket_count() / (float)tableSize;
        }
        return true;
    }

    void erase(const K& key) {
        table[key].clear();
    }

    void clear() {
        table.clear();
    }

    int bucket_count() {
        int count = 0;
        for (int i = 0; i < table.size(); i++) {
            if (table[i].empty() == false) {
                for (int j = 0; j < table[i].size(); j++) {
                    count++;
                }
            }
        }
        return count;
    }

    float load_factor() {
        return loadFactor;
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return 0;       
    }

};

#endif //__CHAINING_HASH_H
