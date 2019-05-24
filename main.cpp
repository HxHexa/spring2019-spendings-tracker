/* main.cpp - main for spending tracker
 * Quang Tran - 5/24/2019
 * For Spring 2019 Spending Tracker project
 * compile and run normally. No special flags needed.
 * */

#include <iostream>
#include "linkedList.cpp"

int main() {
    LList<int> *test = new LList<int>();
    test -> addToEnd(1);
    test -> addToEnd(2);
    test -> addToEnd(3);
    test -> addToEnd(4);
    test -> displayList();
    cout << test -> getLength() << endl;
    return 1;
}
