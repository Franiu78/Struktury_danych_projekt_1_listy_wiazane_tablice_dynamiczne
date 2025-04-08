#include <iostream>
#include <chrono>
#include "DynamicArray.h"
#include "LinkedLIst.h"

using namespace std;
using namespace std::chrono;




int main() {
    int il = 50;
    int rozmiar = 10000;
    LinkedList list;
    DynamicArray arr(rozmiar);
    long long licznik;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();

    for (int i = 0; i < rozmiar; i++)
    {
        arr.pushBack(i);
        list.addToEnd(i);
    }


    // --- pushBack / addToEnd ---
    licznik = 0;
    for (int i = 0; i < il; i++)
    {
        
        start = high_resolution_clock::now();
        arr.pushBack(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        arr.popBack();
        
    }
    cout <<"DA dodaj na koniec " << endl << licznik / il << endl;


    licznik = 0;
    for (int i = 0; i < il; i++)
    {

        start = high_resolution_clock::now();
        list.addToEnd(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        list.deleteFromEnd();

    }
    cout << "LL dodaj na koniec " << endl << licznik / il << endl;



    // --- pushFront / addToStart ---
    licznik = 0;
    for (int i = 0; i < il; i++)
    {

        start = high_resolution_clock::now();
        arr.pushFront(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        arr.popFront();

    }
    cout << "DA dodaj na poczatek " << endl << licznik / il << endl;


    licznik = 0;
    for (int i = 0; i < il; i++)
    {

        start = high_resolution_clock::now();
        list.addToStart(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        list.deleteFromStart();

    }
    cout << "LL dodaj na poczatek " << endl << licznik / il << endl;

    // --- pushAt / addToPosition  ---
    licznik = 0;
    for (int i = 0; i < il; i++) {
        int index = rozmiar / 2;
        start = high_resolution_clock::now();
        arr.pushAt(index, 2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        arr.popAt(index);
    }
    cout << "DA dodaj na wybrany indeks " << endl << licznik / il << endl;

    licznik = 0;
    for (int i = 0; i < il; i++) {
        int index = rozmiar / 2;
        start = high_resolution_clock::now();
        list.addToPosition(2137, index);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        list.deleteFromPos(index);
    }
    cout << "LL dodaj na wybrany indkes " << endl << licznik / il  << endl;

    // --- popBack / deleteFromEnd ---
    licznik = 0;
    for (int i = 0; i < il; i++)
    {

        
        arr.pushBack(2137);
        start = high_resolution_clock::now();  
        arr.popBack();       
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
        

    }
    cout << "DA usun z koniec " << endl << licznik / il << endl;


    licznik = 0;
    for (int i = 0; i < il; i++)
    {        
        list.addToEnd(2137);
        start = high_resolution_clock::now();
        list.deleteFromEnd();
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "LL usun z koniec " << endl << licznik / il << endl;

    // --- popFront / deleteFromStart ---
    licznik = 0;
    for (int i = 0; i < il; i++)
    {   
        arr.pushFront(2137);  
        start = high_resolution_clock::now();
        arr.popFront();
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "DA usun z poczatek " << endl << licznik / il << endl;


    licznik = 0;
    for (int i = 0; i < il; i++)
    {
        list.addToStart(2137);        
        start = high_resolution_clock::now();
        list.deleteFromStart();
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "LL usun z poczatek " << endl << licznik / il << endl;

    // --- popAt / deleteFromPos ---

    licznik = 0;
    for (int i = 0; i < il; i++) {
        int index = rozmiar / 2;
        arr.pushAt(index, 2137);
        start = high_resolution_clock::now();       
        arr.popAt(index);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "DA usun z wybrany indeks " << endl << licznik / il << endl;

    licznik = 0;
    for (int i = 0; i < il; i++) {
        int index = rozmiar / 2;
        list.addToPosition(2137, index);
        start = high_resolution_clock::now();
        list.deleteFromPos(index);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "LL usun z wybrany indkes " << endl << licznik / il << endl;
    // --- search / find  --
    licznik = 0;
    for (int i = 0; i < il; i++) {
        start = high_resolution_clock::now();
        arr.search(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "DA search: " << endl << licznik / il  << endl;

    licznik = 0;
    for (int i = 0; i < il; i++) {
        start = high_resolution_clock::now();
        list.find(2137);
        stop = high_resolution_clock::now();
        licznik += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "LL search: " << endl << licznik / il  << endl;
    
    return 0;
}
