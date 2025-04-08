// Implementacja jednokierunkowej listy wiązanej z węzłami przechowującymi wartości całkowitoliczbowe
#include "LinkedList.h"
#include <stdexcept>

using namespace std;

// Konstruktor węzła - tworzy węzeł z podaną wartością i ustawia wskaźnik next jako nullptr
Node::Node(int val) : data(val), next(nullptr) {}

// Metoda wyświetlająca wartość węzła na standardowe wyjście
void Node::showValue() const {
    cout << data;
}

// Konstruktor listy wiązanej - inicjalizuje pustą listę
LinkedList::LinkedList() : head(nullptr), end(nullptr), counter(0) {}

// Destruktor - zwalnia pamięć zajmowaną przez wszystkie węzły
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

// Sprawdza czy lista jest pusta
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Zwraca liczbę elementów w liście
int LinkedList::size() const {
    return counter;
}

// Dodaje nowy element na początek listy
void LinkedList::addToStart(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        // Jeśli lista jest pusta, nowy węzeł staje się zarówno początkiem jak i końcem
        head = end = newNode;
    } else {
        // Nowy węzeł staje się nowym początkiem listy
        newNode->next = head;
        head = newNode;
    }
    counter++;
    cout << "Dodano element " << val << " na początek." << endl;
}

// Dodaje nowy element na koniec listy
void LinkedList::addToEnd(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        // Jeśli lista jest pusta, nowy węzeł staje się zarówno początkiem jak i końcem
        head = end = newNode;
    } else {
        // Dodajemy nowy węzeł za dotychczasowym końcem listy
        end->next = newNode;
        end = newNode;
    }
    counter++;
    cout << "Dodano element " << val << " na koniec." << endl;
}

// Dodaje nowy element na określoną pozycję w liście
void LinkedList::addToPosition(int val, int pos) {
    if (pos < 0 || pos > counter) {
        throw out_of_range("Nieprawidłowa pozycja!");
    }

    if (pos == 0) {
        // Dodawanie na początek
        addToStart(val);
        return;
    }

    if (pos == counter) {
        // Dodawanie na koniec
        addToEnd(val);
        return;
    }

    // Dodawanie w środku listy
    Node* newNode = new Node(val);
    Node* curr = head;
    // Znajdź węzeł poprzedzający pozycję, na którą wstawiamy
    for (int i = 0; i < pos - 1; i++) {
        curr = curr->next;
    }

    // Wstawiamy nowy węzeł pomiędzy curr i curr->next
    newNode->next = curr->next;
    curr->next = newNode;
    counter++;
    cout << "Dodano element " << val << " na pozycję " << pos << "." << endl;
}

// Usuwa element z początku listy
void LinkedList::deleteFromStart() {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    Node* curr = head;
    int deleteVal = curr->data;

    if (head == end) {
        // Jeśli jest tylko jeden element w liście
        head = end = nullptr;
    } else {
        // Przesuwamy wskaźnik head na następny element
        head = head->next;
    }

    delete curr;
    counter--;
    cout << "Usunięto " << deleteVal << " z początku." << endl;
}

// Usuwa element z końca listy
void LinkedList::deleteFromEnd() {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    int deleteVal = end->data;

    if (head == end) {
        // Jeśli jest tylko jeden element w liście
        delete head;
        head = end = nullptr;
    } else {
        // Musimy znaleźć przedostatni element
        Node* before = head;
        while (before->next != end) {
            before = before->next;
        }
        delete end;
        end = before;
        end->next = nullptr;
    }
    counter--;
    cout << "Usunięto " << deleteVal << " z końca." << endl;
}

// Usuwa element z określonej pozycji
void LinkedList::deleteFromPos(int pos) {
    if (isEmpty()) {
        throw runtime_error("Lista jest pusta!");
    }

    if (pos < 0 || pos >= counter) {
        throw out_of_range("Nieprawidłowa pozycja!");
    }

    if (pos == 0) {
        // Usuwanie z początku
        deleteFromStart();
        return;
    }

    if (pos == counter - 1) {
        // Usuwanie z końca
        deleteFromEnd();
        return;
    }

    // Usuwanie z środka listy
    Node* before = head;
    // Znajdź węzeł poprzedzający ten, który usuwamy
    for (int i = 0; i < pos - 1; ++i) {
        before = before->next;
    }

    Node* toDelete = before->next;
    int deleteVal = toDelete->data;
    before->next = toDelete->next;
    delete toDelete;
    counter--;
    cout << "Usunięto " << deleteVal << " z pozycji " << pos << "." << endl;
}

// Wyszukuje element o podanej wartości i zwraca jego pozycję
int LinkedList::find(int findVal) {
    if (isEmpty()) {
        return -1;
    }

    Node* curr = head;
    int pos = 0;

    // Przeglądamy całą listę w poszukiwaniu elementu
    while (curr != nullptr) {
        if (curr->data == findVal) {
            cout << "Znaleziono wartość " << findVal << " na pozycji " << pos << "." << endl;
            return pos;
        }
        curr = curr->next;
        pos++;
    }

    cout << "Nie znaleziono wartości " << findVal << "." << endl;
    return -1;
}

// Wyświetla zawartość całej listy
void LinkedList::show() const {
    if (isEmpty()) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    cout << "Lista zawiera " << counter << " elementów: ";
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