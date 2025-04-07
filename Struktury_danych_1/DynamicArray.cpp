#include <iostream>
#include "DynamicArray.h"

DynamicArray::DynamicArray(int set_capacity)
{
    size = 0;
    capacity = set_capacity;
    arr = new int[capacity];
}

DynamicArray::~DynamicArray()
{
    delete[] arr; //zwalnia pamięć usuwając obiekt
}

void DynamicArray::resize()
{
    capacity *= 2;
    int* newarr = new int[capacity];
    for (int i = 0; i < size; ++i) newarr[i] = arr[i]; //kopiowanie starych danych 
    delete[] arr;
    arr = newarr; //zastepujemy stary wskaźnik nowym 
}

void DynamicArray::pushBack(int val)
{
    if (size == capacity) resize(); //jezeli jest za mała pojemność powieksz razy 2 
    arr[size] = val;
    size++;
}

void DynamicArray::pushFront(int val)
{
    if (size >= capacity) resize();
    for (int i = size; i > 0; i--) arr[i] = arr[i - 1]; //przepisuje wszystkie wartości o jeden indeks wyżej 
    arr[0] = val;
    size++;
}

void DynamicArray::pushAt(int index, int val)
{
    if (index < 0 || index > size) return;
    if (size >= capacity) resize();
    for (int i = size; i > index; i--) arr[i] = arr[i - 1]; //przepisuje wszystkie wartości większe od index o jeden indeks wyżej 
    arr[index] = val;
    size++;
}
void DynamicArray::popBack()
{
    if (size > 0) size--; 
    //po prostu zmniejsza rozmiar (ostatnia wartość jest niewidoczna) 
}

void DynamicArray::popFront() 
{
    if (size == 0) return;
    for (int i = 0; i < size - 1; i++)  arr[i] = arr[i + 1];
    size--;
    //przesuwa całość o mniejszy indeks i zmniejsza rozmiar
}

void DynamicArray::popAt(int index)
{
    if (index < 0 || index >= size) return; //zabezpieczenie
    for (int i = index; i < size - 1; i++)  arr[i] = arr[i + 1]; 
    size--;
    //przesuwa wszystkie większe od index o jeden w dół
}

int DynamicArray::search(int val) 
{
    for (int i = 0; i < size; ++i) if (arr[i] == val) return i; //zwraca index szukanej wartości 
    return -1; //jeżeli taka nie istnieje zwraca -1 czyli błędną wartość 
}

int DynamicArray::get(int index)
{
    if (index >= 0 && index < size) return arr[index]; //zwraca wartość dla tego indexu
    throw std::out_of_range("Index out of range"); //błąd 
}

void DynamicArray::print() const
{
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
