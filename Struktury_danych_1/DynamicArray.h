#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    void resize();

public:
    DynamicArray(int initialCapacity = 4);
    ~DynamicArray();

    void pushBack(int value);
    void popBack();

    int get(int index) const;
    void set(int index, int value);

    int getSize() const;
    void print() const;
};

#endif // DYNAMIC_ARRAY_H

