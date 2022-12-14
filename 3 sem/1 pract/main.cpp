//
// Created by t.shkolnik
//

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

//Функция побитового вывода значения переменной
void printValue(const unsigned int& value)
{
    int numByte = sizeof(int) * 4;
    unsigned  mask = (1 << (numByte - 1));

    for (int i = 1; i <= numByte; i++)
    {
        cout << ((value & mask) >> (numByte - i));
        mask >>= 1;

        if (i % 4 == 0) { cout << " "; }
    }
}

//Функция установки битов исходного значения переменной в значение 1 (упр. 1)
void setBitsToOne(unsigned int& value)
{
    value |= 0x0809;
}

//Функция установки битов исходного значения переменной в значение 0 (упр. 2)
void setBitsToZero(unsigned int& value)
{
    value &= 0x0FFF;
}

//Функция умножения значения целочисленной переменной (упр. 3)
void multiplyValue(unsigned int& value)
{
    value <<= 2;
}

//Функция деления значения целочисленной переменной (упр. 4)
void divideValue(unsigned int& value)
{
    value >>= 2;
}

//Функция установки определенных битов значения переменной в 0 (упр. 5)
void setBitToZero(unsigned int& value, unsigned int numOfBit)
{
    unsigned int mask = 0x0010;

    value &= (~((mask >> 4) << numOfBit));
}

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    unsigned int* values;
    unsigned int* valuesTest;
    int varietyFlag;
    int arraySize;
    string temp = "       Было                      Стало      \n";

    cout << "Практическая работа №1 'Поразрядные операции и их применение' Школьник Татьяна ИКБО-06-21" << endl;

    cout << "Выберете способ ввода массива:" << endl;

    cout << "1 - вручную (тестовый прогон)" << endl;
    cout << "2 - генератор случайных чисел (рабочий прогон)" << endl;
    cin >> varietyFlag;

    cout << "Введите размер массива от 1 до 5000" << endl;
    cin >> arraySize;
    values = new unsigned int[arraySize];
    valuesTest = new unsigned int[arraySize];

    if (varietyFlag == 1)
    {
        for (int i = 0; i < arraySize; i++)
        {
            cout << "Введите значение для элемента под номером " << i << " : ";
            cin >> values[i];
            valuesTest[i] = values[i];
        }
    }
    else if (varietyFlag == 2)
    {
        for (int i = 0; i < arraySize; i++)
        {
            values[i] = rand() % 65536;
            valuesTest[i] = values[i];
        }
    }
    else { exit(0); }

    cout << "\nУпражнение 1\n" << endl;
    cout << temp;
    for (int i = 0; i < arraySize; i++)
    {
        printValue(values[i]); cout << "      ";

        setBitsToOne(valuesTest[i]);
        printValue(valuesTest[i]); cout << endl;

        valuesTest[i] = values[i];
    }

    cout << "\nУпражнение 2\n" << endl;
    cout << temp;
    for (int i = 0; i < arraySize; i++)
    {
        printValue(values[i]); cout << "      ";

        setBitsToZero(valuesTest[i]);
        printValue(valuesTest[i]); cout << endl;

        valuesTest[i] = values[i];
    }

    cout << "\nУпражнение 3\n" << endl;
    cout << temp;
    for (int i = 0; i < arraySize; i++)
    {
        printValue(values[i]); cout << "      ";

        multiplyValue(valuesTest[i]);
        printValue(valuesTest[i]);

        valuesTest[i] = values[i]; cout << endl;
    }

    cout << "\nУпражнение 4\n" << endl;
    cout << temp;
    for (int i = 0; i < arraySize; i++)
    {
        printValue(values[i]); cout << "      ";

        divideValue(valuesTest[i]);
        printValue(valuesTest[i]); cout << endl;

        valuesTest[i] = values[i];
    }

    cout << "\nУпражнение 5\n" << endl;
    if (varietyFlag == 2)
    {
        cout << temp;
    }
    for (int i = 0; i < arraySize; i++)
    {
        if (varietyFlag == 1)
        {
            int numBit;

            cout << "Введите номер бита (от 0 до 15): ";
            cin >> numBit;
            cout << temp;

            setBitToZero(valuesTest[i], numBit);
        }
        else
        {
            setBitToZero(valuesTest[i], rand() % 16);
        }

        printValue(values[i]); cout << "      ";

        printValue(valuesTest[i]); cout << endl;

        valuesTest[i] = values[i];
    }

    system("pause"); return 0;
}