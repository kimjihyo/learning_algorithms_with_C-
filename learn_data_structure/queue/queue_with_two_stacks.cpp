#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int _val) {
        val = _val;
    }
};

class Stack {
  public:
    ListNode *dummyHead;
    Stack() {
        dummyHead = new ListNode(0);
        dummyHead->next = NULL;
    }
    void push(int _val) {
        ListNode *newNode = new ListNode(_val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
    }

    int pop() {
        ListNode *temp = dummyHead->next;
        int val = temp->val;
        dummyHead->next = temp->next;
        delete temp;
        return val;
    }

    bool isEmpty() {
        if (dummyHead->next == NULL)
            return true;
        else
            return false;
    }
};

class Queue {
    public:
        Stack stack1;
        Stack stack2;

        int peek() {
            shiftStack();
            int val = stack2.pop();
            stack2.push(val);
            return val;
        }

        bool isEmpty() {
            if (stack1.isEmpty() && stack2.isEmpty())
                return true;
            else
                return false;
        }

        void shiftStack() {
            if (stack2.isEmpty()) {
                while (!stack1.isEmpty()) {
                    stack2.push(stack1.pop());
                }
            }
        }

        void enqueue(int _val) {
            stack1.push(_val);
        }

        int dequeue() {
            shiftStack();
            return stack2.pop();
        }
};

int main() {
    Stack myStack;
    Queue myQueue;
    size_t i;

    for (i = 0; i < 1000; i++) {
        myStack.push(i);
        myQueue.enqueue(i);
    }

    while (!myStack.isEmpty()) {
        cout << myStack.pop() << "\t";
    }

    cout << endl << endl << endl;

    while (!myQueue.isEmpty()) {
        cout << myQueue.dequeue() << "\t";
    }

    cout << endl;

    return 0;
}