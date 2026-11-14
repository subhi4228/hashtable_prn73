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
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 17;

// Mid-Square Hash Function
int midSquareHash(int key) {
    int square = key * key;
    string sqStr = to_string(square);
    
    // Left-pad with zeros to make it at least 4 digits
    while (sqStr.length() < 4) {
        sqStr = "0" + sqStr;
    }
    
    // Extract middle 2 digits (index 1 and 2)
    string mid = sqStr.substr(1, 2);
    int midVal = stoi(mid);
    
    return midVal % TABLE_SIZE;
}

int main() {
    int S = 73;
    int dataset[20];

    cout << "============================================" << endl;
    cout << "PRN: 202501100073" << endl;
    cout << "Hash Function: Mid-Square Method (m=17)" << endl;
    cout << "============================================\n" << endl;

    cout << "Dataset & Hash Indices:" << endl;
    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        int index = midSquareHash(dataset[i]);
        cout << "Key [" << setw(2) << dataset[i] 
             << "] -> Hash Index: " << setw(2) << index << endl;
    }

    return 0;
}