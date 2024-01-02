#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findMax(int* arr, int size) 
{
    int max = arr[0];
    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int* arr, int size) 
{
    int min = arr[0];
    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }
    return min;
}

int findAvg(int* arr, int size) 
{
    int sum = 0;
    for (int i = 0; i < size; ++i) 
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int Action(int* arr1, int* arr2, int size1, int size2, int (*func)(int*, int)) 
{
    int result1 = func(arr1, size1);
    int result2 = func(arr2, size2);
    cout << "Array 1: ";
    for (int i = 0; i < size1; ++i) {

        cout << arr1[i] << " ";
    }
    cout << "\n";
    cout << "Array 2: ";
    for (int i = 0; i < size2; ++i) 
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";
    cout << "Result for Array 1: " << result1 << "\n";
    cout << "Result for Array 2: " << result2 << "\n";
    return result1 + result2;
}

int main() 
{
    srand(time(0));
    const int size1 = 5;
    const int size2 = 7;
    int arr1[size1];
    int arr2[size2];
    for (int i = 0; i < size1; ++i)
    {
        arr1[i] = rand() % 100;
    }
    for (int i = 0; i < size2; ++i) 
    {
        arr2[i] = rand() % 100;
    }
    int (*funcPtr)(int*, int);
    int choice;
    cout << "Choose operation:\n";
    cout << "1. Max\n";
    cout << "2. Min\n";
    cout << "3. Avg\n";
    cin >> choice;
    switch (choice) 
    {
    case 1:
        funcPtr = findMax;
        break;
    case 2:
        funcPtr = findMin;
        break;
    case 3:
        funcPtr = findAvg;
        break;
    default:
        cerr << "Invalid choice\n";
        return 1;
    }
    int result = Action(arr1, arr2, size1, size2, funcPtr);
    cout << "Total result: " << result << "\n";
    return 0;
}
