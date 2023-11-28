#include "binary_tree.h"

TreeNode* BinarySearchTree::insertRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return new TreeNode(value);
    }

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    }
    else {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinarySearchTree::inOrderTraversal(TreeNode* node, MyList<int>& values) const{
    if (node != nullptr) {
        inOrderTraversal(node->left, values);
        values.push_back(node->data);
        inOrderTraversal(node->right, values);
    }
}

TreeNode* BinarySearchTree::buildBST(MyList<int>& values, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;

    // Using your implementation of linked list iterator
    MyList<int>::ListNode* midNode = values.begin();
    for (int i = 0; i < mid; ++i) {
        midNode = midNode->next;
    }

    TreeNode* newNode = new TreeNode(midNode->data);
    newNode->left = buildBST(values, start, mid - 1);
    newNode->right = buildBST(values, mid + 1, end);

    return newNode;
}

TreeNode* BinarySearchTree::removeRecursive(TreeNode* node, int value) {
    if (node == nullptr) {
        return node;
    }

    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    }
    else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        node->data = minValue(node->right);
        node->right = removeRecursive(node->right, node->data);
    }

    return node;
}

int BinarySearchTree::minValue(TreeNode* node) const{
    int minValue = node->data;
    while (node->left != nullptr) {
        minValue = node->left->data;
        node = node->left;
    }
    return minValue;
}

bool BinarySearchTree::searchRecursive(TreeNode* node, int value) const{
    if (node == nullptr) {
        return false;
    }

    if (value == node->data) {
        return true;
    }
    else if (value < node->data) {
        return searchRecursive(node->left, value);
    }
    else {
        return searchRecursive(node->right, value);
    }
}

void BinarySearchTree::printRecursive(TreeNode* node, int indent) const{
    if (node != nullptr) {
        if (node->right) {
            printRecursive(node->right, indent + 4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (node->right) {
            cout << " /\n" << setw(indent) << ' ';
        }
        cout << node->data << "\n ";
        if (node->left) {
            cout << setw(indent) << ' ' << " \\\n";
            printRecursive(node->left, indent + 4);
        }
    }
}

