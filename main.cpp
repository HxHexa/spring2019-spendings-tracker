/* main.cpp - main for spending tracker
    test1 -> displayList();
 * Quang Tran - 5/24/2019
 * For Spring 2019 Spending Tracker project
 * compile and run normally. No special flags needed.
 * */

#include <iostream>
#include <string>
#include "hashTable.h"
#include "spendEntry.h"
#include "namedList.h"
#include "linkedList.h"
using namespace std;

int main() {
    auto source = new HashTable<NamedList<SpendEntry>*>();
    auto category = new HashTable<NamedList<SpendEntry>*>();
    auto test1 = new NamedList<int>("test1");
    auto test2 = new NamedList<int>("test2");
    test1 -> displayList();
    test2 -> displayList();
    source -> display();
    category -> display();
    //if (test1 == test2) {
    //    cout << "equal\n";
    //} else cout << "unequal\n";
    return 0;
}
