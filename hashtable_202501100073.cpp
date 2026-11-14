/*
 * PRN: 202501100073
 * Seed S: 73
 * Domain: Cold-drink flavours (PRN mod 3 = 0)
 * Hash Function: Mid-Square Method (PRN is odd)
 * Collision Strategy: Separate Chaining (PRN mod 2 = 1)
 * Table Size m: 17
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 17;

// Linked list node for separate chaining
struct Node {
    int key;
    string flavour;
    Node* next;
    Node(int k, string f) : key(k), flavour(f), next(nullptr) {}
};

int midSquareHash(int key) {
    int square = key * key;
    string sqStr = to_string(square);
    while (sqStr.length() < 4) {
        sqStr = "0" + sqStr;
    }
    string mid = sqStr.substr(1, 2);
    int midVal = stoi(mid);
    return midVal % TABLE_SIZE;
}

// Hash Table using Separate Chaining
class HashTable {
private:
    vector<Node*> table;
public:
    HashTable() {
        table.resize(TABLE_SIZE, nullptr);
    }

    void insert(int key, string flavour) {
        int index = midSquareHash(key);
        Node* newNode = new Node(key, flavour);
        // Separate Chaining: Insert at head of linked list
        newNode->next = table[index];
        table[index] = newNode;
    }
};

int main() {
    int S = 73;
    int dataset[20];
    string flavours[20] = {
        "Cola", "Lemon", "Orange", "Mango", "Grape",
        "Berry", "Peach", "Soda", "Cherry", "Guava",
        "Lychee", "Kiwi", "Melon", "Apple", "Pine",
        "Coconut", "Vanilla", "Rose", "Ginger", "Lime"
    };

    HashTable ht;

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        ht.insert(dataset[i], flavours[i]);
    }

    cout << "Separate Chaining Hash Table initialized & inserted all 20 keys successfully." << endl;

    return 0;
}