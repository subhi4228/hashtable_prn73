/*
 * PRN: 202501100073
 * Seed S: 73
 * Domain: Cold-drink flavours (PRN mod 3 = 0)
 * Hash Function: Mid-Square Method (PRN is odd)
 * Collision Strategy: Attempted direct array insert (no collision handling) - FAILED APPROACH
 * Table Size m: 17
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 17;

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

// Simple Array Hash Table without collision handling (FAILED APPROACH)
class SimpleHashTable {
private:
    int table[TABLE_SIZE];
public:
    SimpleHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) table[i] = -1;
    }

    void insert(int key) {
        int index = midSquareHash(key);
        // Direct overwrite - loses data on collision!
        table[index] = key;
    }

    void display() {
        cout << "\nFlat Array Hash Table (Overwrites on collision):" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << setw(2) << i << " : ";
            if (table[i] == -1) cout << "EMPTY" << endl;
            else cout << table[i] << endl;
        }
    }
};

int main() {
    int S = 73;
    int dataset[20];
    SimpleHashTable ht;

    cout << "============================================" << endl;
    cout << "PRN: 202501100073" << endl;
    cout << "Testing naive direct array insert (NO collision handling)" << endl;
    cout << "============================================\n" << endl;

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        ht.insert(dataset[i]);
    }

    ht.display();

    return 0;
}