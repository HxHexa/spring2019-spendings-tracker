/* main.cpp - main for spending tracker
    test1 -> displayList();
 * Quang Tran - 5/24/2019
 * For Spring 2019 Spending Tracker project
 * compile and run normally. No special flags needed.
 * */

#include <iostream>
#include <string>
#include "hashTable.cpp"
#include "spendEntry.cpp"
#include "namedList.cpp"
#include "linkedList.cpp"
using namespace std;

int main() {
    HashTable<NamedList<int>*>* source = new HashTable<NamedList<int>*>();
    HashTable<NamedList<int>*>* category = new HashTable<NamedList<int>*>();
    NamedList<int>* test1 = new NamedList<int>("test1");
    test1 -> addToEnd(7);
    test1 -> addToEnd(6);
    test1 -> addToEnd(5);
    NamedList<int>* test2 = new NamedList<int>("test1");
    test2 -> addToEnd(7);
    test2 -> addToEnd(6);
    test2 -> addToEnd(5);
    test1 -> displayList(); test2 -> displayList();
    /*if (*test1 == *test2) cout << "equal";
    else cout << "unequal";*/
    source -> insertItem(&test1);
    source -> findItem(&test2);
    source -> deleteItem(&test2);
    test1 -> displayList(); test2 -> displayList();
    source -> display();
    return 0;
}
