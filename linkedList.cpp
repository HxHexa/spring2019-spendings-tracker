/* linkedList.cpp - task1-7 of lab 3 on linked lists
 * Quang Tran - 3/5/2019
 *
 * COMPILE: g++ linkedList.cpp
 * RUN: ./a.out
 * */

#include <iostream>
#include "linkedList.h"
using namespace std;

/* simple initiator that sets startNode as NULL
 * should not take any parameters
 * */
template <class Item>
LList<Item>::LList() {
    startNode = NULL;
    length = 0;
}

/* deconstructor
 * */
template <class Item>
LList<Item>::~LList() {
    while (startNode != NULL) {
        delete removeAtStart();
    }
    delete(startNode);
    cout << "Destroyed list." << endl;
}

/* displayList()
 * input: none
 * return: void
 * displays the list. Used mainly for testing
 * */
template <class Item>
void LList<Item>::displayList() {
    //print a single arrow if startNode is NULL (empty list)
    if (startNode == NULL) {
        cout << ">" << endl;
        return;
    }
    node* travelPointer = startNode; //initializing a pointer for traversing

    //do while loop for traversing and printing the list
    //information from: https://en.cppreference.com/w/cpp/language/do
    do {
        cout << travelPointer -> value << " > ";
        travelPointer = travelPointer -> next;
    } while(travelPointer != NULL);
    cout << endl;
}

/* getLength()
 * input: void
 * return: int
 * returns the length of the list
 * */
template <class Item>
int LList<Item>::getLength() {
    return length;
}

/* addToEnd
 * input: Item value
 * return: void
 * adds an Item object to the list at the end
 * */
template <class Item>
void LList<Item>::addToEnd(Item value) {
    //initializing newNode
    node* newNode = new node(value, NULL);
    //checking whether the first node is NULL
    //if the intention is to have a new list
    //since we have newNode already, just use that
    if (startNode == NULL) {
        startNode = newNode;
        length += 1;
        return;
    }

    node* travelPointer = startNode; //initializing a pointer for traversing

    //while loop that traverses the travelPointer until the end of the lsit
    while (travelPointer -> next != NULL) {
        travelPointer = travelPointer -> next;
    }

    //adding the newNode
    travelPointer -> next = newNode;
    length += 1;
}

/* addToBeginning
 * input: Item value
 * return: void
 * adds an Item object to the list at the beginning
 * */
template <class Item>
void LList<Item>::addToBeginning(Item value) {
    //initialize newNode
    node* newNode = new node(value, NULL);

    //checking whether the newNode is NULL
    //in the case it is, the function ends,
    //startNode NULL case handling is altered for the class
    if (newNode == NULL) {
        return;
    }
    if (startNode == NULL) {
        startNode = newNode;
        length += 1;
        return;
    }
    //setting the next pointer of newNode to the first node
    newNode -> next = startNode;

    //changing the first node to newNode
    startNode = newNode;
    length += 1;
}

/* addAtIndex
 * input: Item value, int index
 * return: int
 * adds an Item object to the list at index given in input
 * returns 0 if success, 1 if failed
 * */
template <class Item>
int LList<Item>::addAtIndex(Item value, int index) {
    //initialize newNode
    node* newNode = new node(value, NULL);

    //for negative index, the function returns an error code
    if (index < 0) {
        return 1;
    }
    //for NULL startNode, the function returns an error code
    //in the case where the user is trying to initialize a new list,
    //then an index would not make sense.
    if (newNode == NULL) {
        return 1;
    }
    //special indices cases
    if (index == 0) {
        addToBeginning(value);
        return 0;
    }
    if (index == length) {
        addToEnd(value);
        return 0;
    }
    if (startNode == NULL) {
        return 1;
    }

    node* traverser = startNode; //initializing a pointer for traversing

    //putting the traverser on the index to add the node
    //if next is NULL, then the function returns an error code
    //in the case someone wants to add a node at the end, just use addToEnd
    for (int i = 1; i < index; i++) {
        if (traverser -> next != NULL) {
            traverser = traverser -> next;
        }
        else {
            return 1;
        }
    }

    //making the newNode points to the nextNode
    //if newNode is NULL, this step is skipped. The list will be cut there.
    //*the "feature" above is now removed bc users could use removeAtEnd instead
    //additionally, it's too much work traversing the rest of the list and
    //delete each one of them for memory purposes
    newNode -> next = traverser -> next;
    //making the traverser, now on the index, points to newNode
    traverser -> next = newNode;
    length += 1;
    return 0;
}

/* removeAtIndex
 * input: int index
 * return: node*
 * remove a value at a designated index
 * returns removed node
 * */
template <class Item>
typename LList<Item>::node* LList<Item>::removeAtIndex(int index) {
    //for negative index, the function returns an error code
    if (index < 0) {
        return NULL;
    }
    //for NULL startNode, the function returns an error code
    //in the case where the user is trying to initialize a new list,
    //then an index would not make sense. Use AddToBeginning instead
    if (startNode == NULL) {
        return NULL;
    }
    //if index = 0 calls removeAtStart
    if (index == 0) {
        return removeAtStart();
    }
    if (index == length - 1) {
        return removeAtEnd();
    }

    node* iterator = startNode;
    node* traverser = startNode; //initializing a pointer for traversing

    //putting the traverser on the index to add the node
    //if next is NULL, then the function returns an error code
    //in the case someone wants to remove a node at the end, just use removeAtEnd
    for (int i = 0; i < index; i++) {
        if (traverser -> next != NULL) {
            iterator = traverser;
            traverser = traverser -> next;
        }
        else {
            return NULL;
        }
    }

    //remove the node
    iterator -> next = traverser -> next;
    traverser -> next = NULL;
    length -= 1;
    return traverser;
}

/* removeByValue
 * input: Item value
 * return: int
 * removes all Item with value given in input
 * returns the number of deleted items
 * */
template <class Item>
int LList<Item>::removeByValue(Item delValue) {
    //checking for NULL startNode
    //there is nothing to remove from a NULL startNode, so the function returns an error
    if (startNode == NULL) {
        return -1;
    }

    //initialize a counter for number of vals deleted
    int counter = 0;

    //initialize an iterator at start
    node* iterator = startNode;
    //initialize a tracker node, for deleting
    node* tracker = startNode;

    //traversing the list, deleting delValue
    //delete command usage found from https://stackoverflow.com/questions/4134323/c-how-to-delete-a-structure
    //if the list has only 1 value, cancels the whole thing and jump to remove startNode
    if (tracker -> next != NULL) {
        while (1) {
            tracker = iterator -> next;
            if (tracker == NULL) {
                break;
            }
            else {
                if (tracker -> value == delValue) {
                    iterator -> next = tracker -> next;
                    delete tracker;
                    counter += 1;
                }
                else {
                    iterator = tracker;
                }
            }
        }
    }

    //special part for removing the start node
    if ((startNode) -> value == delValue) {
        delete removeAtStart();
    }
    length -= counter;

    return counter;
}

/* removeAtStart
 * input: none
 * return: node*
 * remove the value at the start of the list and returns it
 * */
template <class Item>
typename LList<Item>::node* LList<Item>::removeAtStart() {
    //checking whether the startNode is NULL
    if (startNode == NULL) {
        return NULL;
    }
    //copy the part about removing startnode from above
    node* tracker = startNode;
    startNode = startNode -> next;
    length -= 1;
    return tracker;
}

/* removeAtEnd
 * input: none
 * return: node*
 * removes the ending node of the list, returning the removed node
 * */
template <class Item>
typename LList<Item>::node* LList<Item>::removeAtEnd() {
    //checking whether the startNode is NULL
    if (startNode == NULL) {
        return NULL;
    }

    //traverser and tracker
    node* traverser = startNode;
    node* tracker = startNode;

    //special case for when the list has only 1 element: just delete it
    //else, also just delete it
    if (startNode -> next == NULL) {
        startNode = NULL;
        length -= 1;
        return tracker;
    }
    else {
        while (traverser -> next -> next != NULL) {
            traverser = traverser -> next;
        }
    }

    tracker = traverser -> next;
    traverser -> next = NULL;
    length -= 1;
    return tracker;
}

/* findByValue
 * input: Item value
 * return: node*
 * find a node in the list with corresponding value, returning the first iteration
 * */
template <class Item>
typename LList<Item>::node* LList<Item>::findByValue(Item value) {
    //initialize newNode
    node* newNode = new node(value, NULL);
    
    //no NULL startNode
    if (startNode == NULL) {
        return NULL;
    }
    
    //initialize traverser
    node* traverser = startNode;

    //traversing through the list and find the node with the value
    //if found, the node is returned
    while (traverser != NULL) {
        if (traverser -> value == value) {
            return traverser;
        }
        traverser = traverser -> next;
    }

    //default case to return NULL if no node with value is found
    return NULL;
}
