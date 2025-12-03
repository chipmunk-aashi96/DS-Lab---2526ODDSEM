// Q3

#include <iostream>
#include <algorithm>
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

class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* curr = node;
        while (curr && curr->left) curr = curr->left;
        return curr;
    }

    Node* deleteNode(Node* node, int key) {
        if (!node) return node;
        if (key < node->data) node->left = deleteNode(node->left, key);
        else if (key > node->data) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        int left = minDepth(node->left);
        int right = minDepth(node->right);
        if (!node->left || !node->right) return 1 + left + right;
        return 1 + min(left, right);
    }
};

int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 7);

    tree.root = tree.deleteNode(tree.root, 5);

    cout << tree.maxDepth(tree.root) << endl;
    cout << tree.minDepth(tree.root) << endl;

    return 0;
}