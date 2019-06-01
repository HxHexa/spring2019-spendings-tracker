/* namedList.cpp - implementation of namedList.h functions
 * Quang Tran - 5/27/2019
 * */

#include <string>
#include <iostream>
#include "linkedList.h"
#include "namedList.h"
using namespace std;

//very basic implementations
//there might be some work needed to be done in regards to special characters
//or empty string
//for now, this is just a demo that hopefully works
template <class Item>
NamedList<Item>::NamedList(string listName) {
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

template <class Item>
void NamedList<Item>::displayList() {
    cout << name << ": ";
    LList<Item>::displayList();
}

//operator overloading taken from
//https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm
template <class Item>
bool NamedList<Item>::operator== (NamedList<Item> n) {
    if (name != n.getName()) return false;
    else return true;
}
