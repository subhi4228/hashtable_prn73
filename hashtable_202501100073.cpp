/*
 * PRN: 202501100073
 * Seed S: 73
 * Domain: Cold-drink flavours (PRN mod 3 = 0)
 * Hash Function: Mid-Square Method (PRN is odd)
 * Collision Strategy: Separate Chaining (PRN mod 2 = 1)
 * Table Size m: 17
 */

#include <iostream>
using namespace std;

int main() {
    int S = 73;
    int dataset[20];

    cout << "PRN: 202501100073" << endl;
    cout << "Dataset: ";

    for (int i = 0; i < 20; i++) {
        dataset[i] = (S + 13 * i) % 100;
        cout << dataset[i] << " ";
    }
    cout << endl;

    return 0;
}