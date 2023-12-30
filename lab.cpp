#include <iostream>
#include <Windows.h>

using namespace std;

double add(double a, double b) 
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b) 
{
    return a * b;
}

double divide(double a, double b) 
{
    if (b != 0) 
    {
        cout << "Помилка: ділення на нуль!" << endl;
        return 0.0;
    }
    else 
    {
        return a / b;
    }
}

int main() 
{  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double (*operation[4])(double, double) = { add, subtract, multiply, divide };
    cout << "Виберіть операцію:" << endl;
    cout << "1. Додавання" << endl;
    cout << "2. Віднімання" << endl;
    cout << "3. Множення" << endl;
    cout << "4. Ділення" << endl;
    int choice;
    cin >> choice;
    choice = (choice >= 1 && choice <= 4) ? choice - 1 : (cout << "Невірний вибір операції!" << endl, -1);
    double num1, num2;
    cout << "Введіть перше число: ";
    cin >> num1;
    cout << "Введіть друге число: ";
    cin >> num2;
    double result = operation[choice](num1, num2);
    cout << "Результат: " << result << endl;
    return 0;
}
