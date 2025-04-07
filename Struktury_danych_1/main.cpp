#include <iostream>
#include "DynamicArray.h"

int main() {
    DynamicArray arr;

    for (int i = 0; i < 10; ++i)
        arr.pushBack(i);

    arr.print();

    arr.set(3, 999);
    arr.print();

    std::cout << "Element at 3: " << arr.get(3) << "\n";
}
