#pragma once

#include <iostream>
#include <algorithm> 

template <typename T>
class MyList {
public:
    class ListNode {
    public:
        T data;
        ListNode* next;

        ListNode(const T& value) : data(value), next(nullptr) {}

        bool operator==(const ListNode& other) const {
            return data == other.data;
        }
    };

private:
    ListNode* head;
    size_t size;

public:
    MyList();
    void push_back(const T& value);
    size_t get_size() const;
    ListNode* at(size_t index);
    void push_front(const T& value);
    void insert_after(ListNode* node, const T& value);
    ListNode* begin();
    ListNode* end();
    ListNode* getBegin() const;
    void print();
    void copy_from(const MyList& otherList);
    void sort();
    ~MyList();
};