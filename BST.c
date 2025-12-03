#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int item) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

bool search(struct Node* root, int key) {
   
    // root is null -> return false
    if (root == NULL) return false;

    // if root has key -> return true
    if (root->data == key) return true;

    if (key > root->data) return search(root->right, key);

    return search(root->left, key);
}

int main() {
    // Creating BST
    //    6
    //   / \
    //  2   8
    //     / \
    //    7   9
    struct Node* root = newNode(6);
    root->left = newNode(2);
    root->right = newNode(8);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    int key = 9;
    // Searching for key in the BST
    printf("%d\n", search(root, key));
}