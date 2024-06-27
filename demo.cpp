#include <iostream>

using namespace std;

const int X = 7;

struct HashTable {
    int *key;
    int size;

    HashTable(int n) {
        size = n;
        key = new int[size];
    }

    ~HashTable() {
        key = nullptr;
        delete[] key;
    }
};

int hashFunction(int k) {
    return k;
}

int linearProbe(HashTable ht, int k, int i) {
    return (hashFunction(k) + i) % ht.size;
}

void insertValue(HashTable ht, int k) {
    if (ht.key[hashFunction(k)] != 0 || hashFunction(k) > ht.size-1) {
        for (int i = 0; i < ht.size; i++) {
            if (ht.key[linearProbe(ht, k, i)] == 0) {
                ht.key[linearProbe(ht, k, i)] = k;
                break;
            }
        }
    } else {
        cout << "No linear probing.\n";
        cout << "index of hashing: " << hashFunction(k) << endl;
        ht.key[hashFunction(k)] = k;
    }
}

void printHashTable(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        cout << "[" << i << "]: " << ht.key[i] << endl;
    }
}

int main() {
    int a[]{10, 22, 31, 4, 15, 28, 17, 88, 59};
    int m = 11;
    HashTable ht1 = HashTable(m);
    for (int i = 0; i < 9; i++) {
        insertValue(ht1,a[i]);
    }

    printHashTable(ht1);
}