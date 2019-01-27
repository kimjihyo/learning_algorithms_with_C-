#include <iostream>

using namespace std;

class Node {
    public:
        Node *left;
        Node *right;
        int value;

        Node(int _value) {
            left = NULL;
            right = NULL;
            value = _value;
        }

        void insert(int _value) {
            if (this->value > _value) {
                if (this->left == NULL)
                    this->left = new Node(_value);
                else
                    this->left->insert(_value);
            } else {
                if (this->right == NULL)
                    this->right = new Node(_value);
                else
                    this->right->insert(_value);
            }
        }

        void printInOrder() {
            if (this->left != NULL)
                this->left->printInOrder();
            cout << this->value << "\t";
            if (this->right != NULL)
                this->right->printInOrder();
        }
};

bool isValidBST(Node *current, int min, int max) {
    if (current == NULL)
        return true;
    if (current->value < min || current->value > max)
        return false;
    
    return isValidBST(current->left, min, current->value - 1) && isValidBST(current->right, current->value + 1, max);
}

bool isValidBST(Node *root) {
    return isValidBST(root, INT_MIN, INT_MAX);
}

int main() {
    Node *root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(12);
    root->insert(5);
    root->insert(1);
    return 0;
}