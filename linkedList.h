/* linkedList.h - header file for attempting to wrap linkedList up as a class
 * Quang Tran 5/23/2019
 * Final project for Spring2019 - spendings-tracker
 * */

template <class Item>
class LList {
    private:
        struct node {
            Item value;
            node* next;
            node (Item v, node* n) {
                value = v;
                next = n;
            }
        };
        node* startNode;
        int length;

    public:
        LList();
        ~LList();
        void displayList();
        int getLength();
        void addToEnd(Item value);
        void addToBeginning(Item value);
        int addAtIndex(Item value, int index);
        node* removeAtIndex(int index);
        int removeByValue(Item value);
        node* removeAtStart();
        node* removeAtEnd();
        node* findByValue(Item value);

};
