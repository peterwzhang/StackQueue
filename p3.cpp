#include <iostream>

#include "dll.h"
#include "exceptions.h"
#include "stack.h"

using namespace std;

int main() {
    try {
        string ch;
        cout
            << "Enter:\n\t- 'l' for list\n\t- 's' for stack\n\t- 'quit' to quit"
            << endl;
        cin >> ch;

        if (ch == "l") {
            cout << "Enter:\n\t- 'i #r #v' to insert\n\t- 'r #' to remove\n\t- "
                    "'a #' to at\n\t- 's' to get the size\n\t- 'e' to check "
                    "emptiness\n\t- 'c' to clear\n\t- 'q' to quit"
                 << endl;
            string choice;
            int rank;
            int val;
            Dll<int> list;
            while (1) {
                cout << list << endl << endl;
                cin >> choice;
                if (choice == "q") {
                    break;
                }
                if (choice == "i") {
                    cin >> rank >> val;
                    list.insert(rank, val);
                } else if (choice == "r") {
                    cin >> rank;
                    cout << "removed = " << list.remove(rank) << endl;
                } else if (choice == "a") {
                    cin >> rank;
                    cout << "at = " << list.at(rank) << endl;
                } else if (choice == "s") {
                    cout << "size = " << list.size() << endl;
                } else if (choice == "c") {
                    list.clear();
                } else if (choice == "e") {
                    cout << "empty = " << boolalpha << list.empty() << endl;
                }
            }
        } else if (ch == "s") {
            cout << "Enter:\n\t- 'push #' to push\n\t- 'pop' to pop\n\t- "
                    "'peek' to peek\n\t- 'size' to get the size\n\t- 'empty' "
                    "to check emptiness\n\t- 'q' to quit"
                 << endl;
            string choice;
            int val;
            Stack<int> stack;
            while (1) {
                cout << stack << endl << endl;
                cin >> choice;
                if (choice == "q") {
                    break;
                }
                if (choice == "push") {
                    cin >> val;
                    stack.push(val);
                } else if (choice == "pop") {
                    cout << "popped " << stack.pop() << endl;
                } else if (choice == "peek") {
                    cout << "peeked " << stack.peek() << endl;
                } else if (choice == "size") {
                    cout << "size = " << stack.size() << endl;
                } else if (choice == "empty") {
                    cout << "empty = " << boolalpha << stack.empty() << endl;
                }
            }
        }
    } catch (InvalidOperationException &e) {
        cout << e.getMessage() << endl;
    } catch (IndexOutOfRangeException &e) {
        cout << e.getMessage() << " Index=" << e.getIndex() << endl;
    }

    return 0;
}
