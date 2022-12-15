//
// Created by t.shkolnik
//

#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

//Функция вывода значения по битам
void printBinary(unsigned int &x) {
    int n = sizeof(int) * 4;
    unsigned maska = (1 << (n - 1));

    for (int i = 1; i <= n; i++) {
        cout << ((x & maska) >> (n - i));
        maska >>= 1;

        if (i % 4 == 0) { cout << " "; }
    }
}

//Функция устанавливает 0, 3 и 11ый биты переданного значения в 1
void set1InBits(unsigned int &userValue) {
    unsigned int maska = 0x0809; // 0000 1000 0000 1001
    userValue |= maska;
}

//Функция устанавливает старшие 4 бита переданного значения в 0
void set0ToBits(unsigned int &userValue) {
    unsigned int maska = 0x0FFF; // 0000 1111 1111 1111
    userValue &= maska;
}

//Функция умножает значение на 4, используя побитовый сдвиг влево
void multiply(unsigned int &userValue) {
    userValue <<= 2;
}

//Функция делит значение на 4, используя побитовый сдвиг вправо
void divide(unsigned int &userValue) {
    userValue >>= 2;
}

//Функция обнуляет определенные биты переданного значения
void setZeros(unsigned int &userValue, unsigned int n) {
    unsigned int maska = 0x0010;
    unsigned int maskaWith1InEnd = maska >> 4;
    unsigned int maskaWith1AtNPosition = maskaWith1InEnd << n;

    userValue &= ~maskaWith1AtNPosition;
}

//Вводная функция к каждому заданию, выбор режима работы
void onboading(int *arraySize) {
    cout << "Введите размер массива от 1 до 5000" << endl;
    cin >> *arraySize;

    cout << "Выберете способ ввода массива:" << endl;
    cout << "1 - вручную (тестовый прогон)" << endl;
    cout << "2 - генератор случайных чисел (рабочий прогон)" << endl;
}

//Функция считывает элементы массива, введённые пользователем
void readArray(unsigned int *userValues, unsigned int *valuesTest, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << "Введите значение для элемента " << i << " : ";
        cin >> userValues[i];
        valuesTest[i] = userValues[i];
    }
}

//Функция заполняет массив случайными значениями
void generateArray(unsigned int *userValues, unsigned int *valuesTest, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        userValues[i] = rand() % 65536;
        valuesTest[i] = userValues[i];
    }
}

int main(void) {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int menu = 1;
    int workMode;
    int arraySize;
    unsigned int *userValues;
    unsigned int *resultValues;

    cout << "Практическая работа №1 'Поразрядные операции и их применение' Школьник Татьяна ИКБО-06-21" << endl;

    while (menu != 0) {
        cout << "Какое задание выполнить?" << endl;
        cout << "1. Установить биты в единицу 0й, 3й, 11й" << endl;
        cout << "2. Установить старшие 4 бита в ноль" << endl;
        cout << "3. Умножить на 4" << endl;
        cout << "4. Разделить на 4" << endl;
        cout << "5. Обнулить разряд" << endl;

        cin >> menu;

        switch (menu) {
            case 1:
                onboading(&arraySize);
                cin >> workMode;

                userValues = new unsigned int[arraySize];
                resultValues = new unsigned int[arraySize];

                if (workMode == 1) {
                    readArray(userValues, resultValues, arraySize);
                } else if (workMode == 2) {
                    generateArray(userValues, resultValues, arraySize);
                } else { exit(0); }

                cout << "\nУпражнение " << 1 << "\n" << endl;

                for (int i = 0; i < arraySize; i++) {
                    cout << "Исходное значение " << endl;
                    printBinary(userValues[i]);

                    cout << endl << "Изменённое значение " << endl;
                    set1InBits(resultValues[i]);
                    printBinary(resultValues[i]);
                    cout << endl << endl;

                    resultValues[i] = userValues[i];
                }
                break;
            case 2:
                onboading(&arraySize);
                cin >> workMode;

                userValues = new unsigned int[arraySize];
                resultValues = new unsigned int[arraySize];

                if (workMode == 1) {
                    readArray(userValues, resultValues, arraySize);
                } else if (workMode == 2) {
                    generateArray(userValues, resultValues, arraySize);
                } else { exit(0); }

                cout << "\nУпражнение " << 2 << "\n" << endl;

                for (int i = 0; i < arraySize; i++) {
                    cout << "Исходное значение " << endl;
                    printBinary(userValues[i]);

                    cout << endl << "Изменённое значение " << endl;
                    set0ToBits(resultValues[i]);
                    printBinary(resultValues[i]);
                    cout << endl << endl;

                    resultValues[i] = userValues[i];
                }
                break;
            case 3:
                onboading(&arraySize);
                cin >> workMode;

                userValues = new unsigned int[arraySize];
                resultValues = new unsigned int[arraySize];

                if (workMode == 1) {
                    readArray(userValues, resultValues, arraySize);
                } else if (workMode == 2) {
                    generateArray(userValues, resultValues, arraySize);
                } else { exit(0); }

                cout << "\nУпражнение " << 3 << "\n" << endl;

                for (int i = 0; i < arraySize; i++) {
                    cout << "Исходное значение " << endl;
                    printBinary(userValues[i]);

                    cout << endl << "Изменённое значение " << endl;
                    multiply(resultValues[i]);
                    printBinary(resultValues[i]);
                    cout << endl << endl;

                    resultValues[i] = userValues[i];
                }
                break;
            case 4:
                onboading(&arraySize);
                cin >> workMode;

                userValues = new unsigned int[arraySize];
                resultValues = new unsigned int[arraySize];

                if (workMode == 1) {
                    readArray(userValues, resultValues, arraySize);
                } else if (workMode == 2) {
                    generateArray(userValues, resultValues, arraySize);
                } else { exit(0); }

                cout << "\nУпражнение " << 4 << "\n" << endl;

                for (int i = 0; i < arraySize; i++) {
                    cout << "Исходное значение " << endl;
                    printBinary(userValues[i]);

                    cout << endl << "Изменённое значение " << endl;
                    divide(resultValues[i]);
                    printBinary(resultValues[i]);
                    cout << endl << endl;

                    resultValues[i] = userValues[i];
                }
                break;
            case 5:
                onboading(&arraySize);
                cin >> workMode;

                userValues = new unsigned int[arraySize];
                resultValues = new unsigned int[arraySize];

                if (workMode == 1) {
                    readArray(userValues, resultValues, arraySize);
                } else if (workMode == 2) {
                    generateArray(userValues, resultValues, arraySize);
                } else { exit(0); }

                cout << "\nУпражнение " << 5 << "\n" << endl;

                for (int i = 0; i < arraySize; i++) {
                    if (workMode == 1) {
                        int n;
                        cout << "Введите номер бита (от 0 до 15): ";
                        cin >> n;
                        setZeros(resultValues[i], n);
                    } else {
                        int n = rand() % 16;
                        cout << endl << "Обнуляем бит под номером: " << n << endl;
                        setZeros(resultValues[i], n);
                    }

                    cout << "Исходное значение " << endl;
                    printBinary(userValues[i]);

                    cout << endl << "Изменённое значение " << endl;
                    printBinary(resultValues[i]);

                    cout << endl << endl;

                    resultValues[i] = userValues[i];
                }
        }
        break;

    }
    system("pause");
    return 0;
}