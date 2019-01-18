#include <iostream>

using namespace std;

class Node {
    public:
        Node *left, *right;
        int value;

        Node(int _value) {
            left = NULL; right = NULL;
            value = _value;
        }

        void insert(int _value) {
            if (_value < value) {
                if (left == NULL)
                    left = new Node(_value);
                else
                    left->insert(_value);
            } else {
                if (right == NULL)
                    right = new Node(_value);
                else
                    right->insert(_value);
            }
        }

        bool contains(int _value) {
            if (_value == value)
                return true;

            if (_value < value) {
                if (left == NULL)
                    return false;
                else
                    return left->contains(_value);
            } else {
                if (right == NULL)
                    return false;
                else
                    return right->contains(_value);
            }
        }

        void printInOrder() {
            if (left != NULL)
                left->printInOrder();
            cout << value << "\t";
            if (right != NULL)
                right->printInOrder();
        }
};

bool isValidBinaryTree(Node *node, int min, int max)  {
    if (node == NULL)
        return true;
    if (node->value < min || node->value > max)
        return false;
    
    return isValidBinaryTree(node->left, min, node->value - 1) && isValidBinaryTree(node->right, node->value + 1, max);
}

bool isValidBinaryTree(Node *rootNode) {
    return isValidBinaryTree(rootNode, INT_MIN, INT_MAX);
}

int main() {
    Node *rootNode = new Node(10);
    rootNode->insert(5);
    rootNode->insert(12);
    rootNode->insert(7);
    rootNode->insert(3);

    rootNode->printInOrder();
    cout << endl;
    cout << isValidBinaryTree(rootNode)<< endl;
    return 0;
}