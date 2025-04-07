#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val);
    void showValue() const;
};

class LinkedList {
private:
    Node* head;
    Node* end;
    int counter;

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    int size() const;

    void addToStart(int val);
    void addToEnd(int val);
    void addToPosition(int val, int pos);

    void deleteFromStart();
    void deleteFromEnd();
    void deleteFromPos(int pos);

    int find(int findVal);
    void show() const;
};

#endif
