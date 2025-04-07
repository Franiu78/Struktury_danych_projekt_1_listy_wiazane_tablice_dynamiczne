#include <iostream>
#include <chrono>
#include <functional>
#include "DynamicArray.h"
#include "LinkedLIst.h"

using namespace std;
using namespace std::chrono;

// Uniwersalna funkcja do pomiaru czasu działania
void measureTime(const string& label, const function<void()>& func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << label << ": " << duration.count() << " ms" << endl;
}

int main() {
    const int N = 100000;

    DynamicArray arr1(4);
    DynamicArray arr2(4);
    DynamicArray arr3(4);
    DynamicArray arr4(4);
    DynamicArray arr5(4);
    DynamicArray arr6(4);

    // pushBack
    measureTime("pushBack", [&]() {
        for (int i = 0; i < N; ++i)
            arr1.pushBack(i);
        });

    // pushFront
    measureTime("pushFront", [&]() {
        for (int i = 0; i < N; ++i)
            arr2.pushFront(i);
        });

    // pushAt (do środka - liczony ręcznie)
    int currentSize = 0;
    measureTime("pushAt (środek)", [&]() {
        for (int i = 0; i < N; ++i) {
            arr3.pushAt(currentSize / 2, i);
            currentSize++;
        }
        });

    // popBack
    measureTime("popBack", [&]() {
        for (int i = 0; i < N; ++i)
            arr1.popBack();
        });

    // popFront
    measureTime("popFront", [&]() {
        for (int i = 0; i < N; ++i)
            arr2.popFront();
        });

    // popAt (z środka) – przygotowanie
    for (int i = 0; i < N; ++i) arr4.pushBack(i);
    currentSize = N;
    measureTime("popAt (środek)", [&]() {
        for (int i = 0; i < N; ++i) {
            arr4.popAt(currentSize / 2);
            currentSize--;
        }
        });

    // search – przygotowanie
    for (int i = 0; i < N; ++i) arr5.pushBack(i);
    measureTime("search", [&]() {
        for (int i = 0; i < N; ++i)
            arr5.search(i);
        });

    return 0;
}
