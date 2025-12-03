#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

// Insert into BST
Node* insertNode(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

// Search in BST
bool search(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main() {
    Node* root = nullptr;
    int n;

    cout << "How many values you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    cout << "Enter a key to search: ";
    int key;
    cin >> key;

    cout << (search(root, key) ? "Found" : "Not Found") << endl;
}
