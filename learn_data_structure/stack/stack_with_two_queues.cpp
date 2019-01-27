#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int _val) {
        val = _val;
    }
};

class Queue {
    public:
        Node *head;
        Node *tail;

        Queue() {
            head = NULL;
            tail = NULL;
        }

        void enqueue(int val) {
            if (isEmpty()) {
                head = new Node(val);
                tail = head;
                head->next = NULL;
            } else {
                Node *newNode = new Node(val);
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
        }

        int dequeue() {
            if (isEmpty())
                return INT_MIN;
            
            Node *targetNode = head;
            int val = targetNode->val;

            head = targetNode->next;
            delete targetNode;

            return val;
        }

        bool isEmpty() {
            if (head == NULL)
                return true;
            return false;
        }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);

    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.isEmpty() << endl;

    myQueue.enqueue(5);
    myQueue.enqueue(6);

    cout << myQueue.dequeue() << endl;
    cout << myQueue.dequeue() << endl;
    cout << myQueue.isEmpty() << endl;
    
    return 0;
}