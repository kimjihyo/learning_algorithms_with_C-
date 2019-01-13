#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
};

class Queue {
    private:
        Node *head, *tail;
    public:
        int length;
        Queue() {
            head = NULL;
            tail = NULL;
            length = 0;
        }
        int peek() {
            return head->data;
        }

        void enqueue(int value) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->next = NULL;
            if (tail != NULL) {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == NULL) {
                head = newNode;
            }
            length++;
        }

        int dequeue() {
            int data = head->data;
            Node *tempNode = head;
            head = head->next;
            if (head == NULL)
                tail = NULL;
            length--;
            return data;
        }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);

    cout << myQueue.dequeue() << endl;
    return 0;
}