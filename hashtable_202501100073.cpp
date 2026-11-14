/*
 * PRN: 202501100073
 * Seed S: 73
 * Domain: Cold-drink flavours (PRN mod 3 = 0)
 * Hash Function: Mid-Square Method (PRN is odd)
 * Collision Strategy: Separate Chaining (PRN mod 2 = 1)
 * Table Size m: 17
 * Dataset: v[i] = (73 + 13*i) mod 100, i = 0..19
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

// Mid-Square Hash Function
int midSquareHash(int key) {
    int square = key * key;
    string sqStr = to_string(square);
    
    // Left-pad with zeros to guarantee at least 4 digits
    while (sqStr.length() < 4) {
        sqStr = "0" + sqStr;
    }
    
    // Extract middle 2 digits
    string mid = sqStr.substr(1, 2);
    int midVal = stoi(mid);
    
    return midVal % TABLE_SIZE;
}

// Hash Table class with Separate Chaining
class HashTable {
private:
    vector<Node*> table;

public:
    HashTable() {
        table.resize(TABLE_SIZE, nullptr);
    }

    // Insert key-value pair using head-insertion for separate chaining
    void insert(int key, string flavour) {
        int index = midSquareHash(key);
        Node* newNode = new Node(key, flavour);
        newNode->next = table[index];
        table[index] = newNode;

        cout << "  Inserted key=" << setw(2) << key
             << " (" << setw(9) << flavour << ") -> Index "
             << setw(2) << index << endl;
    }

    // Print hash table contents
    void display() {
        cout << "\n========== HASH TABLE (Separate Chaining) ==========" << endl;
        cout << "Table size m = " << TABLE_SIZE << endl;
        cout << "Hash Method : Mid-Square" << endl;
        cout << "=====================================================" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << setw(2) << i << " : ";
            Node* curr = table[i];
            if (curr == nullptr) {
                cout << "NULL";
            }
            while (curr != nullptr) {
                cout << "[" << curr->key << ":" << curr->flavour << "]";
                if (curr->next != nullptr) cout << " -> ";
                curr = curr->next;
            }
            cout << endl;
        }
        cout << "=====================================================" << endl;
    }

    // Destructor to clean up dynamically allocated nodes
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
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

    cout << "============================================" << endl;
    cout << "  PRN       : 202501100073" << endl;
    cout << "  Domain    : Cold-drink flavours" << endl;
    cout << "  Hash Func : Mid-Square Method" << endl;
    cout << "  Collision : Separate Chaining" << endl;
    cout << "  Table Size: 17" << endl;
    cout << "============================================\n" << endl;

    cout << "Dataset: ";
    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        cout << dataset[i] << " ";
    }
    cout << "\n\n--- Insertion Trace ---" << endl;

    HashTable ht;

    for (int i = 0; i < 20; i++) {
        ht.insert(dataset[i], flavours[i]);
    }

    ht.display();

    return 0;
}
