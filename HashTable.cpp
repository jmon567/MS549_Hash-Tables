#include "HashTable.h"
using namespace std;

HashTable::HashTable(int size) : table(size) {}

int HashTable::hashFunction(int key) {
    return key % table.size();
}

void HashTable::insert(int key, int value) {
    cout << "Inserting key: " << key << ", value: " << value << endl;
    int hashIndex = hashFunction(key);
    for (auto& node : table[hashIndex]) {
        if (node.key == key) {
            node.value = value;
            return;
        }
    }
    table[hashIndex].emplace_back(key, value);
}

int HashTable::retrieve(int key) {
    cout << "Retrieving key: " << key << endl;
    int hashIndex = hashFunction(key);
    for (auto& node : table[hashIndex]) {
        if (node.key == key) {
            return node.value;
        }
    }
    return -1; // Indicating key not found
}

void HashTable::remove(int key) {
    cout << "Removing key: " << key << endl;
    int hashIndex = hashFunction(key);
    table[hashIndex].remove_if([key](HashNode& node) { return node.key == key; });
}
