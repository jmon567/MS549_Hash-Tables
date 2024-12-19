#include "HashTable.h"
using namespace std;

HashTableDH::HashTableDH(int size) : size(size), keys(size, -1), values(size), occupied(size, false) {}

int HashTableDH::hashFunction1(int key) {
    return key % size;
}

int HashTableDH::hashFunction2(int key) {
    return (7 - (key % 7)); // Example: using a prime number less than table size
}

void HashTableDH::insert(int key, int value) {
    cout << "Inserting key: " << key << ", value: " << value << " using Double Hashing" << endl;
    int hashIndex = hashFunction1(key);
    int i = 0;
    while (occupied[hashIndex] && i < size) {
        if (keys[hashIndex] == key) {
            values[hashIndex] = value;
            return;
        }
        i++;
        hashIndex = (hashFunction1(key) + i * hashFunction2(key)) % size;
        if (hashIndex < 0) {
            hashIndex += size;
        }
    }
    if (i < size) { // Ensure we are within the bounds of the table
        keys[hashIndex] = key;
        values[hashIndex] = value;
        occupied[hashIndex] = true;
    }
    else {
        cout << "Error: Hash table is full, cannot insert key: " << key << endl;
    }
}

int HashTableDH::retrieve(int key) {
    cout << "Retrieving key: " << key << " using Double Hashing" << endl;
    int hashIndex = hashFunction1(key);
    int i = 0;
    while (occupied[hashIndex] && i < size) {
        if (keys[hashIndex] == key) {
            return values[hashIndex];
        }
        i++;
        hashIndex = (hashFunction1(key) + i * hashFunction2(key)) % size;
        if (hashIndex < 0) {
            hashIndex += size;
        }
    }
    return -1; // Indicating key not found
}

void HashTableDH::remove(int key) {
    cout << "Removing key: " << key << " using Double Hashing" << endl;
    int hashIndex = hashFunction1(key);
    int i = 0;
    while (occupied[hashIndex] && i < size) {
        if (keys[hashIndex] == key) {
            occupied[hashIndex] = false;
            return;
        }
        i++;
        hashIndex = (hashFunction1(key) + i * hashFunction2(key)) % size;
        if (hashIndex < 0) {
            hashIndex += size;
        }
    }
}
