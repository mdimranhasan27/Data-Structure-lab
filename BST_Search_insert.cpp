#include <iostream>
using namespace std;

struct TreeNode {
    int info;
    TreeNode *left, *right;
};

// FIND procedure
void FIND(TreeNode* ROOT, int ITEM, TreeNode*& LOC, TreeNode*& PAR) {
    if (ROOT == nullptr) {
        LOC = nullptr;
        PAR = nullptr;
        return;
    }

    if (ITEM == ROOT->info) {
        LOC = ROOT;
        PAR = nullptr;
        return;
    }

    TreeNode* PTR;
    TreeNode* SAVE;

    if (ITEM < ROOT->info) {
        PTR = ROOT->left;
        SAVE = ROOT;
    } else {
        PTR = ROOT->right;
        SAVE = ROOT;
    }

    while (PTR != nullptr) {
        if (ITEM == PTR->info) {
            LOC = PTR;
            PAR = SAVE;
            return;
        }

        SAVE = PTR;
        if (ITEM < PTR->info)
            PTR = PTR->left;
        else
            PTR = PTR->right;
    }

    LOC = nullptr;
    PAR = SAVE;
}

// INSBST procedure
void INSBST(TreeNode*& ROOT, int ITEM) {
    TreeNode *LOC, *PAR;

    // Step 1: Find where to insert
    FIND(ROOT, ITEM, LOC, PAR);

    // Step 2: Already exists
    if (LOC != nullptr) {
        cout << "Item " << ITEM << " already exists in the tree!\n";
        return;
    }

    // Step 3: Create a new node
    TreeNode* NEWNODE = new TreeNode{ITEM, nullptr, nullptr};

    // Step 4: Attach it
    if (PAR == nullptr) {
        ROOT = NEWNODE; // Tree was empty
    }
    else if (ITEM < PAR->info) {
        PAR->left = NEWNODE;
    }
    else {
        PAR->right = NEWNODE;
    }

    cout << "Inserted " << ITEM << " under parent ";
    if (PAR) cout << PAR->info << endl;
    else cout << "(root)" << endl;
}

// Inorder traversal for checking tree structure
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

int main() {
    // Initial sample BST
    TreeNode* root = new TreeNode{10, nullptr, nullptr};
    root->left = new TreeNode{5, nullptr, nullptr};
    root->right = new TreeNode{15, nullptr, nullptr};
    root->left->left = new TreeNode{3, nullptr, nullptr};
    root->left->right = new TreeNode{7, nullptr, nullptr};

    cout << "Initial tree (inorder): ";
    inorder(root);
    cout << "\n";

    // Test FIND
    TreeNode *loc, *par;
    FIND(root, 7, loc, par);
    if (loc != nullptr) {
        cout << "7 found. Parent = ";
        if (par) cout << par->info << endl;
        else cout << "None (root)" << endl;
    }

    // Test insertion
    cout << "\nInserting 6...\n";
    INSBST(root, 6);

    cout << "\nInserting 12...\n";
    INSBST(root, 12);

    cout << "\nTree after insertions (inorder): ";
    inorder(root);
    cout << "\n";

    return 0;
}
