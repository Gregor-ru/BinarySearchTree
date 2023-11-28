#include "my_list.h"
#include "binary_tree.h"

using namespace std;


int main() {

    // Пример использования, обычное бинарное дерево 
    BinarySearchTree employeeTree;

    // Добавление сотрудников в бинарное дерево
    employeeTree.insert(30);  // Director
    employeeTree.insert(50);  // CEO
    employeeTree.insert(70);  // Manager
    employeeTree.insert(80);  // Project Manager
    employeeTree.insert(40);  // Team Lead
    employeeTree.insert(20);  // Team Lead
    employeeTree.insert(60);  // Project Manager

    cout << "Binary Tree Structure:\n";
    employeeTree.printTree();
    cout << endl;

    // Пример организации иерархии сотрудников с помощью бинарного дерева

    // Преобразование в бинарное дерево поиска
    employeeTree.convertToBinarySearchTree();

    cout << "Binary Search Tree Structure:\n";
    employeeTree.printTree();
    cout << endl;

    // Поиск сотрудника
    MyList<int> searchEmployees;
    searchEmployees.push_back(40);
    searchEmployees.push_back(2000);

    for (size_t i = 0; i < searchEmployees.get_size(); i++) {
        if (employeeTree.search(searchEmployees.at(i)->data)) {
            cout << "Employee with ID " << searchEmployees.at(i) << " is in the company." << endl;
        }
        else {
            cout << "Employee with ID " << searchEmployees.at(i) << " is not found in the company." << endl;
        }
    }

    // Удаление сотрудника
    int removeEmployee = 30;
    employeeTree.remove(removeEmployee);

    // Вывод структуры дерева поиска после удаления
    cout << "Binary Search Tree Structure after removal:\n";
    employeeTree.printTree();
    cout << endl;

    return 0;
}