#ifndef __DLL_H__
#define __DLL_H__
#include <iostream>

#include "exceptions.h"

template <typename T>
class DllNode {
   public:
    T value;
    DllNode *prev;
    DllNode *next;
};

template <typename T>
class Dll {
   private:
   public:
    int listSize;
    DllNode<T> *head;
    DllNode<T> *tail;
    Dll() {
        head = NULL;
        tail = NULL;
        listSize = 0;
    }  // create an empty list
    Dll(const Dll &src) {
        head = NULL;
        tail = NULL;
        listSize = 0;
        DllNode<T> *cur = src.head;
        int count = 0;
        while (cur != NULL) {
            insert(count, cur->value);
            cur = cur->next;
            count++;
        }
    }  // create a deep copy of the src list
    Dll(const T arr[], int size) {
        head = NULL;
        tail = NULL;
        listSize = 0;
        for (int i = 0; i < size; i++) {
            insert(i, arr[i]);
        }
    }  // create a linked list containing the elements of the array
    Dll &operator=(const Dll &src) {
        clear();
        DllNode<T> *cur = src.head;
        int count = 0;
        while (cur != NULL) {
            insert(count, cur->value);
            cur = cur->next;
            count++;
        }
        return *this;
    }  // create a deep copy of the src list
    ~Dll() {
        // DllNode<T> *cur = head;
        clear();
    }  // free all memory

    bool empty() const {
        if (listSize == 0) return true;
        return false;
    }  // return if the list is empty in O(1)
    int size() const {
        return listSize;
    }  // return how many items are in the list in O(1)

    T &at(int rank) {
        if (rank < 0 || rank >= listSize)
            throw IndexOutOfRangeException(
                "at(): Index was outside the bounds of the linked list.",
                rank);  // throw this exception: at(): Index was outside the
                        // bounds of the linked list.
        DllNode<T> *cur = head;
        for (int i = 0; i < rank; i++) {
            cur = cur->next;
        }
        T &retVal = cur->value;
        return retVal;
        // for (DllNode<T> *cur = head; cur->next != NULL; cur = cur->next)
        // {
        //     if (count == rank)
        //     {
        //     T &retVal = cur->value;
        //     return retVal;
        //     }
        //     count++;
        // }

    }  // return a reference to the value of the list at a rank/index
    void insert(int rank, T value) {
        if (rank < 0 || rank > listSize)
            throw IndexOutOfRangeException(
                "insert(): Index was outside the bounds of the linked list.",
                rank);  // throw this exception: insert(): Index was outside the
                        // bounds of the linked list.
        DllNode<T> *newNode = new DllNode<T>;
        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (listSize == 0) {
            head = newNode;
            tail = newNode;
            listSize = 1;
            return;
        }

        if (rank == 0) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            listSize++;
            return;
        }
        if (rank == listSize) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            listSize++;
            return;
        }
        DllNode<T> *cur = head;
        for (int i = 0; i < rank; i++) {
            cur = cur->next;
        }
        DllNode<T> *prevNode = cur->prev;
        newNode->prev = prevNode;
        newNode->next = cur;
        cur->prev = newNode;
        prevNode->next = newNode;
        listSize++;
    }  // insert a value at the rank/index
    T remove(int rank) {
        if (rank < 0 || rank >= listSize)
            throw IndexOutOfRangeException(
                "remove(): Index was outside the bounds of the linked list.",
                rank);  // remove(): Index was outside the bounds of the linked
                        // list.
        int valToReturn = 0;
        if (listSize == 1) {
            DllNode<T> *nodeToDel = head;
            T valToReturn = nodeToDel->value;
            delete nodeToDel;
            head = NULL;
            tail = NULL;
            listSize = 0;
            return valToReturn;
        }

        if (rank == 0) {
            DllNode<T> *newHead = head->next;
            DllNode<T> *nodeToDel = head;
            T valToReturn = nodeToDel->value;
            newHead->prev = NULL;
            head = newHead;
            listSize--;
            delete nodeToDel;
            return valToReturn;
        }
        if (rank == listSize - 1) {
            DllNode<T> *newTail = tail->prev;
            DllNode<T> *nodeToDel = tail;
            T valToReturn = nodeToDel->value;
            newTail->next = NULL;
            tail = newTail;
            delete nodeToDel;
            listSize--;
            return valToReturn;
        }
        DllNode<T> *cur = head;
        for (int i = 0; i < rank; i++) {
            cur = cur->next;
        }
        DllNode<T> *prevNode = cur->prev;
        DllNode<T> *nextNode = cur->next;
        DllNode<T> *nodeToDel = cur;
        T valToReturn2 = nodeToDel->value;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete nodeToDel;
        listSize--;
        return valToReturn2;
    }  // remove the node at the rank/index and return its value

    void clear() {
        DllNode<T> *cur = head;
        while (cur != NULL) {
            DllNode<T> *nodeToDel;
            nodeToDel = cur;
            cur = cur->next;
            delete nodeToDel;
        }
        // cout << listSize << endl << head << endl << tail << endl;
        head = NULL;
        tail = NULL;
        listSize = 0;
    }  // reset the list to an empty list
    void display(ostream &os) const {
        if (head == NULL) {
            os << "[ ]";
            return;
        }
        os << "[ ";
        DllNode<T> *cur = head;
        while (cur != NULL) {
            os << cur->value << " ";
            cur = cur->next;
        }
        os << "]";
    }  // write the contents of the list to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Dll<T> &list) {
    list.display(os);
    return os;
}  // write the contents of the list to the ostream

#endif
