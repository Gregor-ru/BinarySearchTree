#include <iostream>
#include <vector>

using namespace std;

// ����������� ���� ��������� ������
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    // �����������
    TreeNode(int value, TreeNode* parent = nullptr) : data(value), left(nullptr), right(nullptr), parent(parent) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // ����������� ������� �������� � ������
    void insert(int value) {
        root = insertRecursive(root, nullptr, value);
    }

    // ����������� �������� �������� �� ������
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // ����� �������� � ������
    bool search(int value) const {
        return searchRecursive(root, value);
    }

    // ����� ������ � ������� �����������
    void inorderTraversal() const {
        inorderTraversalRecursive(root);
    }

private:

    TreeNode* insertRecursive(TreeNode* node, TreeNode* parent, int value) {
        if (node == nullptr) {
            return new TreeNode(value, parent);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, node, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, node, value);
        }

        return node;
    }

    TreeNode* removeRecursive(TreeNode* node, int value) {
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
                if (temp != nullptr) {
                    temp->parent = node->parent;
                }
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                if (temp != nullptr) {
                    temp->parent = node->parent;
                }
                delete node;
                return temp;
            }

            node->data = minValue(node->right);
            node->right = removeRecursive(node->right, node->data);
        }

        return node;
    }

    int minValue(TreeNode* node) const {
        int minValue = node->data;
        while (node->left != nullptr) {
            minValue = node->left->data;
            node = node->left;
        }
        return minValue;
    }

    bool searchRecursive(TreeNode* node, int value) const {
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

    void inorderTraversalRecursive(TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

    // ������ ������
    TreeNode* root;
};

int main() {

    // ������ �������������, ������ ����������� ��������

    BinarySearchTree employeeTree;

    // ���������� ����������� � �������� ������
    employeeTree.insert(50);  // CEO
    employeeTree.insert(30);  // Director
    employeeTree.insert(70);  // Manager
    employeeTree.insert(20);  // Team Lead
    employeeTree.insert(40);  // Team Lead
    employeeTree.insert(60);  // Project Manager
    employeeTree.insert(80);  // Project Manager

    // ����� �������� ����������� � ������� �����������
    cout << "Employee Hierarchy:\n";
    employeeTree.inorderTraversal();
    cout << endl;

    // ����� ����������

    vector<int> searchEmployees;

    searchEmployees.push_back(40);
    searchEmployees.push_back(2000);

    for (int i = 0; i < searchEmployees.size(); i++)
    {
        if (employeeTree.search(searchEmployees[i])) {
            cout << "Employee with ID " << searchEmployees[i] << " is in the company." << endl;
        }
        else {
            cout << "Employee with ID " << searchEmployees[i] << " is not found in the company." << endl;
        }
    }


    // �������� ����������
    int removeEmployee = 30;
    employeeTree.remove(removeEmployee);

    // ����� �������� ����� ��������
    cout << "Employee Hierarchy after removal:\n";
    employeeTree.inorderTraversal();
    cout << endl;

    return 0;
}
