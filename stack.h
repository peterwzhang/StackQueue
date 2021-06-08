#ifndef __STACK_H__
#define __STACK_H__

#include "dll.h"
#include "exceptions.h"

template <typename T>
class Stack {
   private:
    Dll<T> stackList;

   public:
    Stack() {
        stackList.head = NULL;
        stackList.tail = NULL;
        stackList.listSize = 0;
    }  // create an empty stack
    void push(T value) {
        stackList.insert(0, value);
    }  // add an item to the top of the stack
    T pop() {
        if (stackList.listSize == 0)
            throw InvalidOperationException("Stack empty.");
        return stackList.remove(0);

    }  // remove of the value at the top of the stack and return its value
    T peek() {
        if (stackList.listSize == 0)
            throw InvalidOperationException("Stack empty.");
        return stackList.at(0);
    }  // return the value at the top of the stack, keeping it in the stack
    int size() const {
        return stackList.listSize;
    }  // return how many items are in the stack
    bool empty() const {
        if (stackList.listSize == 0) return true;
        return false;
    }  // return if the stack is empty
    void display(ostream &os) const {
        if (stackList.head == NULL) {
            os << "[ ]";
            return;
        }
        os << "[ ";
        DllNode<T> *cur = stackList.head;
        while (cur != NULL) {
            os << cur->value << " ";
            cur = cur->next;
        }
        os << "]";
    }  // write the contents of the stack to the ostream
};

template <typename T>
ostream &operator<<(ostream &os, const Stack<T> &stack) {
    stack.display(os);
    return os;
}  // write the contents of the stack to the ostream

#endif
