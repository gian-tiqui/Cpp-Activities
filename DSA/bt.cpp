#include <iostream>
#include <stack>

using std::cout;
using std::stack;

class Node {
    int key;
    Node *left, *right;

public:
    Node() {
        key = 0;
        left = right = NULL;
    }

    Node(int data) {
        key = data;
        left = right = NULL;
    }

    Node *insert(Node *root, int data) {
        if (root == NULL) root = new Node(data);
        else if (data < root->key) root->left = insert(root->left, data);
        else root->right = insert(root->right, data);

        return root;
    }

    void in_order(Node *root) {
        Node* curr = root;
        Node* last = root;
        stack<Node *> nodes;
        
        while (curr) {
            
        }
    }
};
