#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    currentPos = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {

}

template<class T>
bool UnsortedList<T>::IsFull() const {
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node<T>* curr = head;

    while (curr != nullptr) {
        if (curr->info == someItem) {
            return true;
        }

        curr = curr->next; //move current to next node in list
    }

    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {
    Node<T>* loc = new Node<T>; //creates a new block of address memory (location)
    loc->info = item; //set info address to item

    loc->next = head; //set head address memory to loc

    head = loc;
    length++; //increment length AKA book keeping
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {

    if (length > 0 && head->info == item) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
        return;
    }

    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr != nullptr) {
        if (curr->info == item) {
            prev->next = curr->next; //sets prev to curr
            delete curr; //remove curr memory address to avoid memory leak
            length--; //decrement to book keep
            return;
        }

        prev = curr; //previous will always be pointing to item before curr
        curr = curr->next; //move current to next node in list
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currentPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    //handle edge cases
    if (currentPos == nullptr) {
        throw "Nothing to iterate over";
    }

    T currVal = currentPos->info;
    currentPos = currentPos->next;
    return currVal;
}
