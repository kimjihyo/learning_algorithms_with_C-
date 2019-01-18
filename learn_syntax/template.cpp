#include <iostream>

using namespace std;

template <class T>
struct ListNode {
    T value;
    ListNode *next;
    ListNode(T _value) {
        value = _value;
    }
};


int main() {
    ListNode<int> *head = new ListNode<int>(1);
    head->next = NULL;
    cout << head->value << endl;
    
    return 0;
}