#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashNode {
public:
    int key;
    int value;
    HashNode(int k, int v) : key(k), value(v) {}
};

class HashTable {
private:
    vector<list<HashNode>> table;
    int hashFunction(int key);

public:
    HashTable(int size);
    void insert(int key, int value);
    int retrieve(int key);
    void remove(int key);
};

// New HashTableDH class for Double Hashing
class HashTableDH {
private:
    vector<int> keys;
    vector<int> values;
    vector<bool> occupied;
    int size;
    int hashFunction1(int key);
    int hashFunction2(int key);

public:
    HashTableDH(int size);
    void insert(int key, int value);
    int retrieve(int key);
    void remove(int key);
};

#endif // HASHTABLE_H


