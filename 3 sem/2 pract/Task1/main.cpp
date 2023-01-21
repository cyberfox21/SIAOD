////
//// Created by t.shkolnik
////
//
//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <ctime>
//#include <fstream>
//
//#include "functions.h"
//
//using namespace std;
//
////Вводная функция, выбор задания
//void onboarding() {
//    cout << "Практическая работа №2 'Внешние структуры данных: текстовый и двоичный файлы' Татьяна ИКБО-06-21" << endl;
//    cout << "Что вы хотите сделать?" << endl;
//    cout << "1. Создание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке"
//         << endl;
//    cout << "2. Вывод содержимого текстового файла" << endl;
//    cout << "3. Добавление новой строки в конец файла" << endl;
//    cout << "4. Прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение" << endl;
//    cout << "5. Определить количество чисел в файле" << endl;
//    cout << "6. Создать два новых файла из значений исходного, "
//            "\nпереписав в один из них первую половину чисел исходного, "
//            "\nа в другой, оставшуюся часть. В исходный файл слить данные их двух новых файлов "
//            "\nупорядоченными по возрастанию парами, т.е. прочитать первые числа двух файлов, "
//            "\nсначала в исходный файл записать меньшее из них, а за ним большее." << endl;
//    cout << "0. Выход" << endl;
//}
//
//void task1() {
//    string fileName;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    createFileWithRandomNumbers(fileName);
//}
//
//void task2() {
//    string fileName;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    print(fileName);
//}
//
//void task3() {
//    string fileName;
//    string stringThatAdd;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    cout << "Введите строку, которую нужно добавить в конец: ";
//    getline(cin, stringThatAdd);
//    addLine(stringThatAdd, fileName);
//}
//
//void task4() {
//    int positionNum;
//    string fileName;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    cout << "Введите номер числа: ";
//    cin >> positionNum;
//    positionNum = readNumber(fileName, positionNum);
//    cout << positionNum << endl;
//}
//
//void task5(){
//    string fileName;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    cout << numbersCount(fileName) << endl;
//}
//
//void task6() {
//    string fileName;
//    cout << "Имя файла: ";
//    cin.get();
//    getline(cin, fileName);
//    additionalOperation(fileName);
//    cout << "Создан новый файл " + fileName + "Updated.txt" << endl;
//}
//
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    srand(time(NULL));
//
//    int menu = 1;
//
//    while (menu != 0) {
//        onboarding();
//        cin >> menu;
//        switch (menu) {
//            case 1: task1(); break;
//            case 2: task2(); break;
//            case 3: task3(); break;
//            case 4: task4(); break;
//            case 5: task5(); break;
//            case 6: task6(); break;
//        }
//    }
//
//    system("pause");
//    return 0;
//}
