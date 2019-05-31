/* namedList.cpp - implementation of namedList.h functions
 * Quang Tran - 5/27/2019
 * */

#include <string>
#include "linkedList.h"
#include "namedList.h"
using namespace std;

//very basic implementations
//there might be some work needed to be done in regards to special characters
//or empty string
//for now, this is just a demo that hopefully works
template <class Item>
NamedList<Item>::NamedList(string listName) {
    LList<Item>();
    name = listName;
}

template <class Item>
void NamedList<Item>::rename(string newName) {
    name = newName;
}

template <class Item>
string NamedList<Item>::getName() {
    return name;
}

//operator overloading taken from
//https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm
template <class Item>
bool NamedList<Item>::operator== (NamedList<Item> n) {
    if (this -> getName() != n -> getName()) return false;
    else if (this -> getLength() != n -> getLength()) return false;
    else {
        //I think typename is here to tell the compiler that node* is a type
        //taken from https://en.cppreference.com/w/cpp/keyword/typename
        typename NamedList<Item>::node* traverser1 = this -> startNode;
        typename NamedList<Item>::node* traverser2 = n -> startNode;
        while (traverser1 != NULL) {
            if (traverser1 -> value != traverser2 -> value) {
                return false;
            }
            traverser1 = traverser1 -> next;
            traverser2 = traverser2 -> next;
        }
        return true;
    }
}
