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
        cout << "�������: ������ �� ����!" << endl;
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
    cout << "������� ��������:" << endl;
    cout << "1. ���������" << endl;
    cout << "2. ³�������" << endl;
    cout << "3. ��������" << endl;
    cout << "4. ĳ�����" << endl;
    int choice;
    cin >> choice;
    choice = (choice >= 1 && choice <= 4) ? choice - 1 : (cout << "������� ���� ��������!" << endl, -1);
    double num1, num2;
    cout << "������ ����� �����: ";
    cin >> num1;
    cout << "������ ����� �����: ";
    cin >> num2;
    double result = operation[choice](num1, num2);
    cout << "���������: " << result << endl;
    return 0;
}
