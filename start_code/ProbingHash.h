#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<K, V>> table;
    int tableSize = 0;
    float loadFactor = 0.75;

public:
    ProbingHash(int n = 11) {
        this->tableSize = n;
        for (int i = 0; i < tableSize; i++) {
            pair<K, V> newPair;
            newPair.first = VALID;
            newPair.second = VALID;
            table.push_back(newPair);
        }
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->tableSize;
    }

    V operator[](const K& key) {
        return table[key].second;
    }

    bool insert(const std::pair<K, V>& pair) {
        table[pair.first] = pair;
        // Re-hashing

        // Determine load factor
        loadFactor = (float)bucket_count() / (float)tableSize;

        // Resize table to next prime number
        if (loadFactor > 0.75) {
            tableSize = findNextPrime(tableSize + 1);

            vector<std::pair<K, V>> temp(tableSize);
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
        table[key].first = DELETED;
        table[key].second = DELETED;
    }

    void clear() {
        table.clear();
    }

    int bucket_count() {
        int count = 0;
        for (int i = 0; i < table.size(); i++) {
            if (table[i].first != DELETED && table[i].first != EMPTY && table[i].first != VALID) {
                count++;
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

#endif //__PROBING_HASH_H
