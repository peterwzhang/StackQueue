#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "dll.h"
#include "exceptions.h"

template <typename T>
class Queue {
   private:
    Dll<T> queueList;

   public:
    Queue() {
        queueList.head = NULL;
        queueList.tail = NULL;
        queueList.listSize = 0;
    }  // create an empty stack
    void enqueue(T value) {
        queueList.insert(0, value);
    }  // add an item to the front of the queue
    T dequeue() {
        if (queueList.listSize == 0)
            throw InvalidOperationException("Queue empty.");
        return queueList.remove(queueList.listSize - 1);
    }  // remove the value at the front of the queue and return its value
    T peek() {
        if (queueList.listSize == 0)
            throw InvalidOperationException("Queue empty.");
        return queueList.at(queueList.listSize - 1);
    }  // return the value at the front of the queue, keeping it in the queue
    int size() const {
        return queueList.listSize;
    }  // return how many items are in the queue
    bool empty() const {
        if (queueList.listSize == 0) return true;
        return false;
    }  // return if the queue is empty
    void display(ostream &os) const {
        if (queueList.head == NULL) {
            os << "[ ]";
            return;
        }
        os << "[ ";
        DllNode<T> *cur = queueList.tail;
        while (cur != NULL) {
            os << cur->value << " ";
            cur = cur->prev;
        }
        os << "]";
    }  // write the contents of the queue to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Queue<T> &queue) {
    queue.display(os);
    return os;
}  // write the contents of the queue to the ostream

#endif
