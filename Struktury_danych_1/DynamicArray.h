#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* arr;         
    int size;
    int capacity;
    void resize();

public:
    DynamicArray(int set_capacity);
    ~DynamicArray();

    void pushBack(int val);
    void pushFront(int val);
    void pushAt(int index, int val);

    
    
    void popBack();
    void popFront();
    void popAt(int index);

    int search(int val);
    int get(int index);

    void print() const;
};

#endif
