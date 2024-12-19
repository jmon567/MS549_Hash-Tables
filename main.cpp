#include "HashTable.h"
#include <chrono>
#include <random>
#include <vector>
using namespace std;
using namespace chrono;

struct TestResult {
    string tableType;
    string operation;
    int iterations;
    long long duration;
};

void testHashTable(HashTable& ht, int iterations, vector<TestResult>& results) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10000);

    // Insert
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        int value = distribution(generator);
        ht.insert(key, value);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Chaining", "Insert", iterations, duration });
    cout << "Debug: Insert " << iterations << " items in Chaining took " << duration << " ms" << endl;

    // Retrieve
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        ht.retrieve(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Chaining", "Retrieve", iterations, duration });
    cout << "Debug: Retrieve " << iterations << " items in Chaining took " << duration << " ms" << endl;

    // Remove
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        ht.remove(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Chaining", "Remove", iterations, duration });
    cout << "Debug: Remove " << iterations << " items in Chaining took " << duration << " ms" << endl;
}

void testHashTableDH(HashTableDH& ht, int iterations, vector<TestResult>& results) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 10000);

    // Insert
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        int value = distribution(generator);
        ht.insert(key, value);
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Double Hashing", "Insert", iterations, duration });
    cout << "Debug: Insert " << iterations << " items in Double Hashing took " << duration << " ms" << endl;

    // Retrieve
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        ht.retrieve(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Double Hashing", "Retrieve", iterations, duration });
    cout << "Debug: Retrieve " << iterations << " items in Double Hashing took " << duration << " ms" << endl;

    // Remove
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        int key = distribution(generator);
        ht.remove(key);
    }
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start).count();
    results.push_back({ "Double Hashing", "Remove", iterations, duration });
    cout << "Debug: Remove " << iterations << " items in Double Hashing took " << duration << " ms" << endl;
}

int main() {
    vector<TestResult> results;

    cout << "Testing HashTable using Chaining:" << endl;
    HashTable ht(1000);
    testHashTable(ht, 100, results);
    testHashTable(ht, 1000, results);
    testHashTable(ht, 10000, results);

    cout << "\nTesting HashTable using Double Hashing:" << endl;
    HashTableDH htDH(1000);
    testHashTableDH(htDH, 100, results);
    testHashTableDH(htDH, 1000, results);
    testHashTableDH(htDH, 10000, results);

    cout << "\nTest Results:" << endl;
    for (const auto& result : results) {
        cout << "Table: " << result.tableType
            << ", Operation: " << result.operation
            << ", Iterations: " << result.iterations
            << ", Time: " << result.duration << " ms" << endl;
    }

    return 0;
}
