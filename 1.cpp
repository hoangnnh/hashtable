#include <iostream>

using namespace std;

const int HASH = 11;

struct Node {
    int key;
    Node *next;

    Node() : key(0), next(nullptr) {}

    Node(int data) : key(data), next(nullptr) {}
};

struct List {
    Node *head;
    Node *tail;

    List() : head(nullptr), tail(nullptr) {}
};

struct HashTable {
    int size;
    List *key;

    HashTable(int n) {
        size = n;
        key = new List[size];
    }
};

int hashing(int k) {
    return k % HASH;
}

void addTail(List &l, int data) {
    if (l.head == nullptr)
        l.head = l.tail = new Node(data);
    else {
        Node *temp = new Node(data);
        l.tail->next = temp;
        l.tail = temp;
    }
}

void printList(List l) {
    Node *temp = l.head;
    while (temp != nullptr) {
        cout << temp->key;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
}

void insertValue(HashTable ht, int k) {
    addTail(ht.key[hashing(k)], k);
}

void printHashTable(HashTable ht) {
    for (int i = 0; i < ht.size; i++) {
        cout << "[" << i << "]: ";
        printList(ht.key[i]);
        cout << endl;
    }
}

int main() {
    HashTable ht1 = HashTable(11);
    insertValue(ht1, 7);
    insertValue(ht1, 20);
    insertValue(ht1, 16);
    insertValue(ht1, 24);
    insertValue(ht1, 12);
    insertValue(ht1, 40);
    insertValue(ht1, 15);
    printHashTable(ht1);
}