#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
    private:
        Node *head, *tail;
    public:
        int length;

        LinkedList() {
            head = NULL;
            tail = NULL;
            length = 0;
        }

        int getLength() {
            Node *temp = head;
            int length = 0;
            while (temp != NULL) {
                temp = temp->next;
                length++;
            }
            return length;
        }

        void display() {
            Node *temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
            cout << endl;
        }

        void insertNodeAtTheEnd(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
            length++;
        }

        void insertNodeAtFirst(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
            length++;
        }

        int getValueAt(int index) {
            Node* temp = head;
            int i = 0;
            while (temp != NULL) {
                if (i == index)
                    return temp->data;
                i++;
                temp = temp->next;
            }

            return 12314;
        }

        Node* getNodeAt(int index) {
            Node* temp = head;
            int i = 0;
            while (temp != NULL) {
                if (i == index)
                    return temp;
                i++;
                temp = temp->next;
            }
            return NULL;
        }
        void insertAt(int index, int value) {
            if (index == 0) {
                insertNodeAtFirst(value);
            } else if (index == length - 1) {
                insertNodeAtTheEnd(value);
            } else {
                Node *temp = new Node;
                temp->data = value;
                Node *previous = this->getNodeAt(index - 1);
                temp->next = previous->next;
                previous->next = temp;
            }
            length++;
        }

        void clear() {
            Node *temp = head;
            Node *nextNode = temp->next;
            while (nextNode != NULL) {
                delete temp;
                temp = nextNode;
                nextNode = nextNode->next;
            }
            delete nextNode;
            head = NULL;
            tail = NULL;
            length = 0;
        }

        void deleteFirstNode() {
            Node *temp = head;
            head = head->next;
            delete temp;
            length--;
        }

        void deleteLastNode() {
            Node *temp = tail;
            Node *previous = getNodeAt(length - 2);
            tail = previous;
            previous->next = NULL;
            delete temp;
            length--;
        }

        void deleteAt(int index) {
            if (index == 0) {
                deleteFirstNode();
            } else if (index == length - 1) {
                deleteLastNode();
            } else {
                Node *previous = getNodeAt(index - 1);
                Node *temp = previous->next;
                previous->next = temp->next;
                delete temp;
            }
            length--;
        }

        int* toArray() {
            int *tempArray = (int*)malloc(sizeof(int) * length);
            int i = 0;
            Node* temp = head;
            
            while (temp != NULL) {
                tempArray[i] = temp->data;
                i++;
                temp = temp->next;
            }

            return tempArray;
        }
};

int main() {
    LinkedList myList;
    int sizeOfList = 10;
    int i;

    for (i = 1; i < sizeOfList + 1; i++) {
        myList.insertNodeAtTheEnd(i);
    }
    myList.display();
    cout << myList.length << endl;
    cout << endl;
    myList.deleteFirstNode();
    myList.display();
    cout << myList.length << endl;

    myList.deleteLastNode();
    myList.display();
    cout << myList.length << endl << endl;
    
    myList.deleteAt(5);
    myList.display();
    cout << myList.length << endl << endl;

    int* myArray = myList.toArray();
    cout << sizeof(myArray) << endl;
    for (i = 0; i < myList.length; i++) {
        cout << myArray[i] << endl;
    }
    return 0;
}
