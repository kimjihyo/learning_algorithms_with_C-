#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;
    
    public:
        int length;
        Stack() {
            length = 0;
            top = NULL;
        }
        void push(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = top;
            top = newNode;
            length++;
        }

        int pop() {
            if (length == 0) {
                throw "Stack is empty";
            }
            Node* tempNode = top;
            int returnValue = tempNode->data;
            top = tempNode->next;

            delete tempNode;
            length--;
            return returnValue;
        }
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << "length: " << myStack.length << endl;

    cout << "pop: " << myStack.pop() << endl;

    return 0;
}