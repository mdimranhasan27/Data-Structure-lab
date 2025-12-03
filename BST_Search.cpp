#include <iostream>
using namespace std;

struct TreeNode {
    int info;
    TreeNode *left, *right;
};

// Procedure 7.45: FIND(INFO, LEFT, RIGHT, ROOT, ITEM, LOC, PAR)
void FIND(TreeNode* ROOT, int ITEM, TreeNode*& LOC, TreeNode*& PAR) {
    // 1. [Tree empty?]
    if (ROOT == nullptr) {
        LOC = nullptr;
        PAR = nullptr;
        return;
    }

    // 2. [ITEM at root?]
    if (ITEM == ROOT->info) {
        LOC = ROOT;
        PAR = nullptr;
        return;
    }

    // 3. [Initialize pointers PTR and SAVE.]
    TreeNode* PTR;
    TreeNode* SAVE;

    if (ITEM < ROOT->info) {
        PTR = ROOT->left;
        SAVE = ROOT;
    } else {
        PTR = ROOT->right;
        SAVE = ROOT;
    }

    // 4. Repeat Steps 5 and 6 while PTR != NULL:
    while (PTR != nullptr) {
        // 5. [ITEM found?]
        if (ITEM == PTR->info) {
            LOC = PTR;
            PAR = SAVE;
            return;
        }

        // 6. [Move to left or right child]
        if (ITEM < PTR->info) {
            SAVE = PTR;
            PTR = PTR->left;
        } else {
            SAVE = PTR;
            PTR = PTR->right;
        }
    }

    // 7. [Search unsuccessful.]
    LOC = nullptr;
    PAR = SAVE;
    // 8. Exit.
}
int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode{10, nullptr, nullptr};
    root->left = new TreeNode{5, nullptr, nullptr};
    root->right = new TreeNode{15, nullptr, nullptr};
    root->left->left = new TreeNode{3, nullptr, nullptr};
    root->left->right = new TreeNode{7, nullptr, nullptr};

    TreeNode *loc, *par;
    int item_to_find = 7;

    FIND(root, item_to_find, loc, par);

    if (loc != nullptr) {
        cout << "Item " << item_to_find << " found at location " << loc << endl;
        if (par != nullptr) {
            cout << "Parent is at location " << par << " with value " << par->info << endl;
        } else {
            cout << "Item is the root." << endl;
        }
    } else {
        cout << "Item " << item_to_find << " not found. Can be added as child of " << par->info << endl;
    }

    // Example for a non-existent item
    int item_to_add = 6;
    FIND(root, item_to_add, loc, par);
    if (loc == nullptr && par != nullptr) {
        cout << "Item " << item_to_add << " not found. Can be added as child of " << par->info << endl;
    }

    // Clean up memory (simple example, proper deallocation needed for real applications)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

