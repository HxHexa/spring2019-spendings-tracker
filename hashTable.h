/* hashTable.h - header file for hash table structure
 * supports a maximum of 20 items
 * Quang Tran 5/30/2019
 * Part of finals
 * */

//#include guard found from
//https://en.wikipedia.org/wiki/Include_guard
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "namedList.h"
#define MAX_ELE_COUNT 20
#define ARRAY_LENGTH 23

using namespace std;

template <class Item>
class HashTable {
    private:
        //using an array of pointers to object type Item here
        //makes it easier for deletion by setting to NULL
        Item* table[ARRAY_LENGTH];
        int status_table[ARRAY_LENGTH];
        int eleCount = 0;

        //imiplementation of multiple hash function using function overloading from
        //https://stackoverflow.com/questions/6053444/c-template-method-changing-the-behavior-based-on-the-template-class
        //i decided to not have a default template case after all. In afterthought,
        //that was a dumb idea
        int hashFunction(int value) {
            return value % ARRAY_LENGTH;
        }
        //ARRAY_LENGTH - 4 is 19, for the purpose of getting good results
        int hashFunctionIterator(int value) {
            return value % (ARRAY_LENGTH - 4);
        }

        //iterating over string using range-based for loop found at
        //https://www.techiedelight.com/iterate-over-characters-string-cpp/
        int hashFunction(string value) {
            int hashValue = 0;
            int weight = 1;
            for (const char& i : value) {
                hashValue += weight * i;
                weight += 2;
            }
            return hashFunction(hashValue);
        }
        int hashFunctionIterator(string value) {
            int hashValue = 0;
            int weight = 1;
            for (const char& i : value) {
                hashValue += weight * i;
                weight += 2;
            }
            return hashFunctionIterator(hashValue);
        }

        template <class T>
        int hashFunction(NamedList<T>* value) {
            return hashFunction(value -> getName());
        }
        template <class T>
        int hashFunctionIterator(NamedList<T>* value) {
            return hashFunctionIterator(value -> getName());
        }
    public:
        HashTable();
        ~HashTable();
        void insertItem(Item*);
        Item* findItem(Item*);
        Item* deleteItem(Item*);

        int hashTest(Item*);
        int hashTestIterator(Item*);
        void display();
};

#endif
