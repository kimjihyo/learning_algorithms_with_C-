#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val)
    {
        val = _val;
    }
};

ListNode* reverseList(ListNode *head) {
    ListNode *dummyNode = new ListNode(0);
    ListNode *newNode = new ListNode(head->val);
    ListNode *current = head->next;
    dummyNode->next = newNode;
    newNode->next = NULL;

    while (current != NULL) {
        newNode = new ListNode(current->val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        current = current->next;
    }

    return dummyNode->next;
}

void displayList(ListNode* head) {
    ListNode *current = head;

    while(current != NULL) {
        cout << current->val << "\t";
        current = current->next;
    }
    cout << endl;
}

bool isPalindrome(ListNode *head) {
    ListNode *current = head;
    ListNode *reverse = reverseList(head);
    cout << "isPalindrome: ";
    while (reverse != NULL) {
        if (reverse->val != current->val)
            return false;
        reverse = reverse->next;
        current = current->next;
    }
    return true;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = NULL;
    displayList(head);
    temp = reverseList(head);
    displayList(temp);
    displayList(head);

    cout << isPalindrome(temp) << endl;

    return 0;
}