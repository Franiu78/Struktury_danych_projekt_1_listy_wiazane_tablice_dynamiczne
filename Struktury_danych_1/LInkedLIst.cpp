#include "LinkedList.h"
#include <stdexcept>

using namespace std;

// Node implementation
Node::Node(int val) : data(val), next(nullptr) {}

void Node::showValue() const {
    cout << data;
}

// LinkedList implementation
LinkedList::LinkedList() : head(nullptr), end(nullptr), counter(0) {}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    end = nullptr;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

int LinkedList::size() const {
    return counter;
}

void LinkedList::addToStart(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = end = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    counter++;
    //cout << "Dodano element " << val << " na początek." << endl;
}

void LinkedList::addToEnd(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        head = end = newNode;
    }
    else {
        end->next = newNode;
        end = newNode;
    }
    counter++;
    //cout << "Dodano element " << val << " na koniec." << endl;
}

void LinkedList::addToPosition(int val, int pos) {
    if (pos < 0 || pos > counter) {
        throw out_of_range("Nieprawidłowa pozycja!");
    }

    if (pos == 0) {
        addToStart(val);
        return;
    }

    if (pos == counter) {
        addToEnd(val);
        return;
    }

    Node* newNode = new Node(val);
    Node* curr = head;
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    counter++;
    //cout << "Dodano element " << val << " na pozycję " << pos << "." << endl;
}

void LinkedList::deleteFromStart() {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    Node* curr = head;
    int deleteVal = curr->data;

    if (head == end) {
        head = end = nullptr;
    }
    else {
        head = head->next;
    }

    delete curr;
    counter--;
   // cout << "Usunięto " << deleteVal << " z początku." << endl;
}

void LinkedList::deleteFromEnd() {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    int deleteVal = end->data;

    if (head == end) {
        delete head;
        head = end = nullptr;
    }
    else {
        Node* before = head;
        while (before->next != end) {
            before = before->next;
        }
        delete end;
        end = before;
        end->next = nullptr;
    }
    counter--;
    //cout << "Usunięto " << deleteVal << " z końca." << endl;
}

void LinkedList::deleteFromPos(int pos) {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    if (pos < 0 || pos >= counter) {
        throw out_of_range("Nieprawidłowa pozycja!");
    }

    if (pos == 0) {
        deleteFromStart();
        return;
    }

    if (pos == counter - 1) {
        deleteFromEnd();
        return;
    }

    Node* before = head;
    for (int i = 0; i < pos - 1; ++i) {
        before = before->next;
    }

    Node* toDelete = before->next;
    int deleteVal = toDelete->data;
    before->next = toDelete->next;
    delete toDelete;
    counter--;
  //  cout << "Usunięto " << deleteVal << " z pozycji " << pos << "." << endl;
}

int LinkedList::find(int findVal) {
    if (isEmpty()) {
        return -1;
    }

    Node* curr = head;
    int pos = 0;

    while (curr != nullptr) {
        if (curr->data == findVal) {
      //      cout << "Znaleziono wartość " << findVal << " na pozycji " << pos << "." << endl;
            return pos;
        }
        curr = curr->next;
        pos++;
    }

    //cout << "Nie znaleziono wartości " << findVal << "." << endl;
    return -1;
}

void LinkedList::show() const {
    if (isEmpty()) {
    //    cout << "Lista jest pusta." << endl;
        return;
    }

  //  cout << "Lista zawiera " << counter << " elementów: ";
    Node* curr = head;
    while (curr != nullptr) {
        curr->showValue();
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}
