#pragma once

#include <iostream>
#include <algorithm> 
#include <iomanip>   

#include "my_list.h"

using namespace std;

// Определение узла бинарного дерева
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Конструктор
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // Рекурсивная вставка элемента в дерево
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Преобразование в бинарное дерево поиска
    void convertToBinarySearchTree() {
        MyList<int> values;
        inOrderTraversal(root, values);
        values.sort();
        root = buildBST(values, 0, values.get_size() - 1);
    }

    // Рекурсивное удаление элемента из дерева
    void remove(int value) {
        root = removeRecursive(root, value);
    }

    // Поиск элемента в дереве
    bool search(int value) const {
        return searchRecursive(root, value);
    }

    // Вывод структуры дерева
    void printTree() const {
        printRecursive(root, 0);
    }

private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int value);

    void inOrderTraversal(TreeNode* node, MyList<int>& values) const;

    TreeNode* buildBST(MyList<int>& values, int start, int end);

    TreeNode* removeRecursive(TreeNode* node, int value);

    int minValue(TreeNode* node) const;

    bool searchRecursive(TreeNode* node, int value) const;

    void printRecursive(TreeNode* node, int indent) const;
};
