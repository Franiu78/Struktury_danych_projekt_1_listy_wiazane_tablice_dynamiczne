#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialCapacity) {
    size = 0;
    capacity = initialCapacity;
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

void DynamicArray::pushBack(int value) {
    if (size == capacity)
        resize();
    data[size++] = value;
}

void DynamicArray::popBack() {
    if (size > 0)
        --size;
}

int DynamicArray::get(int index) const {
    if (index >= 0 && index < size)
        return data[index];
    throw std::out_of_range("Index out of range");
}

void DynamicArray::set(int index, int value) {
    if (index >= 0 && index < size)
        data[index] = value;
    else
        throw std::out_of_range("Index out of range");
}

int DynamicArray::getSize() const {
    return size;
}

void DynamicArray::print() const {
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}
