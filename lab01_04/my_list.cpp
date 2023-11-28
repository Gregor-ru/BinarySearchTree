#include "my_list.h"

template <typename T>
MyList<T>::MyList() : head(nullptr), size(0) {}

template <typename T>
size_t MyList<T>::get_size() const {
    return size;
}

template <typename T>
void MyList<T>::push_back(const T& value) {
    if (head == nullptr) {
        head = new ListNode(value);
    }
    else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
    size++;
}

template <typename T>
typename MyList<T>::ListNode* MyList<T>::at(size_t index) {
    if (index < size) {
        ListNode* current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current;
    }
    return nullptr;
}

template <typename T>
void MyList<T>::push_front(const T& value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
    size++;
}

template <typename T>
typename MyList<T>::ListNode* MyList<T>::begin() {
    return head;
}

template <typename T>
typename MyList<T>::ListNode* MyList<T>::getBegin() const {
    return head;
}

template <typename T>
typename MyList<T>::ListNode* MyList<T>::end() {
    return nullptr;
}

template <typename T>
void MyList<T>::insert_after(MyList<T>::ListNode* node, const T& value) {
    if (node) {
        ListNode* newNode = new ListNode(value);
        newNode->next = node->next;
        node->next = newNode;
        size++;
    }
    else {
        push_back(value);
    }
}

template <typename T>
void MyList<T>::print() {
    MyList<T>::ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void MyList<T>::copy_from(const MyList<T>& otherList) {

    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    ListNode* otherCurrent = otherList.head;
    while (otherCurrent != nullptr) {
        push_back(otherCurrent->data);
        otherCurrent = otherCurrent->next;
    }
}

template <typename T>
void MyList<T>::sort() {
    if (size <= 1) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        ListNode* current = head;
        ListNode* next = head->next;

        while (next != nullptr) {
            if (current->data > next->data) {
                T temp = current->data;
                current->data = next->data;
                next->data = temp;

                swapped = true;
            }

            current = next;
            next = next->next;
        }
    } while (swapped);
}


template <typename T>
MyList<T>::~MyList() {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

template class MyList<int>;