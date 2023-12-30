#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

void sumArrs(const int* arrA, const int* arrB, int* arrC, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        arrC[i] = arrA[i] + arrB[i];
    }
}

void printArr(const int* arr, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5;
    srand(time(0));
    int arrA[size];
    int arrB[size];
    int arrC[size];
    for (int i = 0; i < size; ++i) 
    {
        arrA[i] = rand() % 10 + 1;
        arrB[i] = rand() % 10 + 1;
    }
    void (*sumFunction)(const int*, const int*, int*, int) = sumArrs;
    sumFunction(arrA, arrB, arrC, size);
    cout << "Масив A: ";
    printArr(arrA, size);
    cout << "Масив B: ";
    printArr(arrB, size);
    cout << "Масив C (сума A і B): ";
    printArr(arrC, size);
    return 0;
}
