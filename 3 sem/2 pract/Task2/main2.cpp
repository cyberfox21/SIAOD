//
// Created by t.shkolnik
//

#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>

#include "functions2.h"

using namespace std;

//Вводная функция, выбор задания
void onboarding() {
    cout << "Практическая работа №2 'Внешние структуры данных: текстовый и двоичный файлы' Школьник Татьяна ИКБО-06-21" << endl;
    cout << "Что вы хотите сделать?" << endl;
    cout << "1. Преобразование тестовых данных из текстового файла в двоичный файл" << endl;
    cout << "2. Преобразование данных из двоичного файла в текстовыйа" << endl;
    cout << "3. Вывод всех записей двоичного файла" << endl;
    cout << "4. Доступ к записи по ее порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле;" << endl;
    cout << "5. Удаление записи с заданным значением ключа, выполнить путем замены на последнюю запись" << endl;
    cout << "6. Сформировать список нарушений по автомобилю заданного номера. "
            "Результат сохранить в новом двоичном файле с той же структурой записи, что и исходный файл." << endl;
    cout << "7. Увеличить сумму штрафа вдвое по всем авто за указанную дату и по заданной статье." << endl;
    cout << "0. Выход" << endl;
}

void task1() {
    string fileName;
    cout << "Имя файла: ";
    cin.get();
    getline(cin, fileName);
    convertTextToBin(fileName);
    cout << "New binary file " + fileName + "Bin.dat" << endl;
}

void task2() {
    string fileName;
    cout << "Имя файла: ";
    cin.get();
    getline(cin, fileName);
    convertBinToText(fileName);
    cout << "New text file " + fileName + "Text.txt" << endl;
}

void task3() {
    string fileName;
    string stringThatAdd;
    cout << "Имя файла: ";
    cin.get();
    getline(cin, fileName);
    print(fileName);
}

void task4() {
    int positionNum;
    string fileName;
    cout << "Имя файла: ";
    cin.get();
    getline(cin, fileName);
    cout << "Введите номер записи: ";
    cin >> positionNum;
    if(positionNum < 1) {
        cout << "Неправильный порядковый номер" << endl;
    } else {
        positionNum -= 1; // т.к. нужен индекс
        TrafficViolation trafficViolation = getRecord(fileName, positionNum);
        cout << trafficViolation.autoNumber << endl;
        cout << trafficViolation.ownerFIO << endl;
        cout << trafficViolation.model << endl;
        cout << trafficViolation.date << endl;
        cout << trafficViolation.place << endl;
        cout << trafficViolation.article << endl;
        cout << trafficViolation.punishment << endl;
    }
}

void task5(){
    string fileName;
    int autoNumber;
    cout << "Имя файла: ";
    cin.get();
    getline(cin, fileName);
    cout << "Введите номер автомобиля: ";
    cin >> autoNumber;
    deleteRecordAndReplaceByLast(fileName, autoNumber);
}

void task6() {
    string fileName;
    string newFileName;
    int autoNumber;
    cout << "Имя исходного файла: ";
    cin.get();
    getline(cin, fileName);
    cout << "Имя результирующего файла: ";
    cin.get();
    getline(cin, newFileName);
    cout << "Введите номер автомобиля: ";
    cin >> autoNumber;
    createFileWithViolationsByAutoNumber(fileName, newFileName, autoNumber);
    cout << "New file is " + newFileName + ".dat" << endl;
}

void task7() {
    string fileName;
    int date;
    int article;
    cout << "Имя исходного файла: ";
    cin.get();
    getline(cin, fileName);
    cout << "Дата нарушения: ";
    cin >> date;
    cout << "Статья(КоАП): ";
    cin >> article;
    doubleIncreasePunishmentByDateAndArticle(fileName, date, article);
    cout << "Updated file is DoublePunishment" + fileName + ".dat" << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int menu = 1;

    while (menu != 0) {
        onboarding();
        cin >> menu;
        switch (menu) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
        }
    }

    system("pause");
    return 0;
}
