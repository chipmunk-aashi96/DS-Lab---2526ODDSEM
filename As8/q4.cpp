// Q4

#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    bool isBST() {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    BinaryTree t;
    t.root = new Node(10);
    t.root->left = new Node(5);
    t.root->right = new Node(15);
    t.root->right->left = new Node(12);
    t.root->right->right = new Node(20);

    if (t.isBST()) cout << "BST";
    else cout << "Not BST";

    return 0;
}