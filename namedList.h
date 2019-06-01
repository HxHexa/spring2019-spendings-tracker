/* namedList.h - header for named list class
 * basically a linked list but with a name, for use with hashing funcs
 * Quang Tran - 5/27/2019
 * Spring2019 final project - spendings-tracker
 *
 * info on inheritance in C++ found here:
 * https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
 * */

#ifndef NAMEDLIST_H
#define NAMEDLIST_H

#include <string>
#include "linkedList.h"
using namespace std;

template <class Item>
class NamedList: public LList<Item> {
    private:
        string name;
    public:
        NamedList(string listName);
        void rename(string newName);
        string getName();
        void displayList();
        bool operator== (NamedList<Item>);
};

#endif
