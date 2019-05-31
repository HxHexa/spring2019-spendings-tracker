/* hashTable.cpp - implementations of functions in header file
 * Quang Tran 5/31/2019
 * Part of finals
 * */

#include <iostream>
#include "hashTable.h"
using namespace std;

template <class Item>
HashTable<Item>::HashTable() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        status_table[i] = 0;
        table[i] = NULL;
    }
    eleCount = 0;
}

template <class Item>
HashTable<Item>::~HashTable() {
    //value not taken from memory heap so delete table[i] is unneccesary, apparently
    //https://stackoverflow.com/questions/9235770/segfault-when-deleting-pointer
    //for values passed in, delete them individually
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        table[i] = NULL;
    }
    cout << "Destroyed hash table.\n";
}

template <class Item>
void HashTable<Item>::insertItem(Item* newEntry) {
    if (eleCount >= MAX_ELE_COUNT) {
        cout << "Maximum number of values in table reached (20)." << endl;
        return;
    }
    int hashValue = hashFunction(*newEntry);
    int iteratorValue = hashFunctionIterator(*newEntry);
    while(true) {
        if (table[hashValue] == NULL) {
            table[hashValue] = newEntry;
            status_table[hashValue] = 1;
            eleCount += 1;
            break;
        }
        else if (*table[hashValue] == *newEntry) {
            cout << "Duplicate value.\n";
            break;
        }
        else {
            hashValue = (hashValue + iteratorValue) % ARRAY_LENGTH;
        }
    }
    return;
}

template <class Item>
Item* HashTable<Item>::findItem(Item* findEntry) {
    int hashValue = hashFunction(*findEntry);
    int iteratorValue = hashFunctionIterator(*findEntry);
    while(true) {
        cout << hashValue << " " << status_table[hashValue] << endl;
        if (table[hashValue] != NULL && *table[hashValue] == *findEntry) {
            cout << "Item found at index " << hashValue;
            return findEntry;
        }
        else if (status_table[hashValue] == 0) {
            cout << "Item not found.\n";
            return NULL;
        }
        else {
            hashValue = (hashValue + iteratorValue) % ARRAY_LENGTH;
        }
    }
}

template <class Item>
Item* HashTable<Item>::deleteItem(Item* deleteEntry) {
    int hashValue = hashFunction(*deleteEntry);
    int iteratorValue = hashFunctionIterator(*deleteEntry);
    while(true) {
        if (table[hashValue] != NULL && *table[hashValue] == *deleteEntry) {
            status_table[hashValue] = -1;
            table[hashValue] = NULL;
            return deleteEntry;
        }
        else if (status_table[hashValue] == 0) {
            cout << "Item not found.\n";
            return NULL;
        }
        else {
            hashValue = (hashValue + iteratorValue) % ARRAY_LENGTH;
        }

    }
}

//for testing purposes
template<class Item>
int HashTable<Item>::hashTest(Item* value) {
    return hashFunction(*value);
}

template<class Item>
int HashTable<Item>::hashTestIterator(Item* value) {
    return hashFunctionIterator(*value);
}

template<class Item>
void HashTable<Item>::display() {
    cout << "Elements Count: " << eleCount << endl;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << i << " " << status_table[i] << " ";
        if (table[i] == NULL) {
            cout << "NULL";
        }
        else {
            cout << *table[i] << " " << table[i];
        }
        cout << endl;
    }
}
