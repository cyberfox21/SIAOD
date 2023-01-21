//
// Created by t.shkolnik
//

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// ������� �������� ���������� ����� ��������� ASCII,
// ����������� ���������� ����� �� ��������� ����� �� ������
void createFileWithRandomNumbers(string &fileName) {
    srand(time(NULL));
    ofstream file;
    file.open(fileName + ".txt");
    if (file.is_open()) {
        int maxL = rand() % 10 + 1; // +1 ����� ���� ���� 1 ������
        for (int line = 0; line < maxL; line++) {
            int maxN = rand() % 10 + 1; // +1, ����� �� ���� ������ �����
            for (int number = 0; number < maxN; number++) {
                file << rand() % 100 + 1;
                if (number != (maxN - 1)) {
                    file << " ";
                }
            }
            if (line != (maxL-1)) {
                file << endl;
            }
        }
        if (file.good()) {
            file.close();
        }
    }
}

// ������� ������ ����������� ���������� �����
void print(string &fileName) {
    ifstream file;
    file.open(fileName + ".txt");
    string line = "";
    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            cout << line << endl;
        }
        file.close();
    }
}

// ������� ���������� ����� ������ � ����� �����
void addLine(string &additionLine, string &fileName) {
    ofstream file;
    file.open(fileName + ".txt", ios::app);
    if (file.is_open()) {
        file << endl << additionLine;
        if (file.good()) {
            file.close();
        }
    }
}

// ������� ������ �������� �����, ��������� ��� ���������� ����� � �����, � ���������� ��� ��������
int readNumber(string &fileName, int &index) {
    if (index < 0) {
        cout << "������������ ���������� �����" << endl;
    } else {
        int resultNumber;
        ifstream file;
        file.open(fileName + ".txt");
        if (file.is_open()) {
            for (int i = 0; i < index; i++) {
                file >> resultNumber;
            }
            if (!file.good()) {
                cout << "������������ ���������� �����" << endl;
            }
            file.close();
            return resultNumber;
        }
    }
}

// ������� ����������� ���������� ����� � �����
int numbersCount(string &fileName) {
    ifstream file;
    int counter = 0;
    string number;
    file.open(fileName + ".txt");
    if (file.is_open()) {
        while (file.good()) {
            file >> number;
            counter++;
        }
        file.close();
    }
    return counter;
}

// ������� �������� ������ ����� �� �������� ���������,
// ��������� ������� �� ��� ����� � ������ � �������� �������������� �� ����������� ������
void additionalOperation(string &fileName) {
    int flag = 0;

    ifstream file;
    file.open(fileName + ".txt");

    int sourceFileSize = numbersCount(fileName);
    int halfSourceFileSize = floor((sourceFileSize / 2));

    string fileNameA = "fileA";
    string fileNameB = "fileB";

    int number;

    ofstream fileB;
    ofstream fileA;
    fileA.open(fileNameA + ".txt");

    // ��������� �������� ���� �� ���
    if (file.is_open()) {
        for (int i = 0; i < sourceFileSize; i++) {
            if (i < halfSourceFileSize) {
                file >> number;
                fileA << number << endl;
            } else {
                if (flag == 0) {
                    fileA.close();
                    fileB.open(fileNameB + ".txt");
                    flag = 1;
                }
                file >> number;
                fileB << number << endl;
            }
        }
        if (fileB.good()) {
            fileB.close();
            if (file.good()) {
                file.close();
            }
        }
    }

    int numberFromA;
    int numberFromB;

    ifstream forReadFileB;
    ifstream forReadFileA;
    ofstream fileForRecord;

    fileForRecord.open(fileName + "Updated" + ".txt");
    forReadFileA.open(fileNameA + ".txt");
    forReadFileB.open(fileNameB + ".txt");

    flag = 0;

    // ������� ����� �� ���� ������ � �������� ���� �������������� ������
    if (fileForRecord.is_open()) {
        for (int i = 0; i < sourceFileSize - halfSourceFileSize; i++) {
            if (i < halfSourceFileSize) {
                forReadFileA >> numberFromA;
                forReadFileB >> numberFromB;
                if (numberFromA < numberFromB) {
                    fileForRecord << numberFromA << " ";
                    fileForRecord << numberFromB << endl;
                } else {
                    fileForRecord << numberFromB << " ";
                    fileForRecord << numberFromA << endl;
                }
            } else {
                if (flag == 0) {
                    forReadFileA.close();
                    flag = 1;
                }
                forReadFileB >> numberFromB;
                fileForRecord << numberFromB << endl;
            }
        }
        if (forReadFileB.good()) {
            forReadFileB.close();
            if (fileForRecord.good()) {
                fileForRecord.close();
            }
        }
    }
}
