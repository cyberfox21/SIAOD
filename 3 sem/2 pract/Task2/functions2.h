//
// Created by t.shkolnik
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TrafficViolation {
    int autoNumber;
    char ownerFIO[50];
    char model[20];
    int date;
    char place[50];
    int article;
    int punishment;
};

void convertTextToBin(string &fileName) {
    ifstream textFile;
    textFile.open(fileName + ".txt");
    ofstream binFile;
    binFile.open(fileName + "Bin.dat", ios::binary);
    if (textFile.is_open() && binFile.is_open()) {
        while (textFile.good() && binFile.good()) {
            TrafficViolation trafficViolation{};
            string line;
            textFile >> trafficViolation.autoNumber;
            textFile.get();
            getline(textFile, line);
            strcpy(trafficViolation.ownerFIO, line.c_str());
            getline(textFile, line);
            strcpy(trafficViolation.model, line.c_str());
            textFile >> trafficViolation.date;
            textFile.get();
            getline(textFile, line);
            strcpy(trafficViolation.place, line.c_str());
            textFile >> trafficViolation.article;
            textFile.get();
            textFile >> trafficViolation.punishment;
            textFile.get();
            binFile.write((char *) (&trafficViolation), sizeof(trafficViolation));
            binFile.clear();
        }
        textFile.close();
        binFile.close();
    }
}

void convertBinToText(string &fileName) {
    ifstream binFile;
    binFile.open(fileName + ".dat", ios::binary);
    ofstream textFile;
    textFile.open(fileName + "Text.txt");
    if (binFile.is_open() && textFile.is_open()) {
        TrafficViolation trafficViolation{};
        bool isFirstString = true;
        while (binFile.read((char *) &trafficViolation, sizeof(TrafficViolation))) {
            if (!isFirstString) {
                textFile << '\n';
            } else { isFirstString = false; }
            textFile << trafficViolation.autoNumber;
            textFile << '\n' << trafficViolation.ownerFIO;
            textFile << '\n' << trafficViolation.model;
            textFile << '\n' << trafficViolation.date;
            textFile << '\n' << trafficViolation.place;
            textFile << '\n' << trafficViolation.article;
            textFile << '\n' << trafficViolation.punishment;
        }
        binFile.clear();
        textFile.clear();
        if (binFile.good() && textFile.good()) {
            binFile.close();
            textFile.close();
        }
    }
}

void print(string &fileName) {
    ifstream binFile;
    binFile.open(fileName + ".dat", ios::binary);
    if (binFile.is_open()) {
        while (binFile.good()) {
            TrafficViolation trafficViolation;
            binFile.read((char *) &trafficViolation, sizeof(TrafficViolation));
            cout << "------------" << endl;
            cout << trafficViolation.autoNumber << endl;
            cout << trafficViolation.ownerFIO << endl;
            cout << trafficViolation.model << endl;
            cout << trafficViolation.date << endl;
            cout << trafficViolation.place << endl;
            cout << trafficViolation.article << endl;
            cout << trafficViolation.punishment << endl;
        }
        binFile.close();
    }
}

TrafficViolation getRecord(string &fileName, int &index) {
    TrafficViolation trafficViolation;
    ifstream binFile;
    binFile.open(fileName + ".dat", ios::binary);
    binFile.seekg(index * sizeof(TrafficViolation), ios::beg);
    binFile.read((char *) (&trafficViolation), sizeof(TrafficViolation));
    return trafficViolation;
}

void deleteRecordAndReplaceByLast(string &fileName, int &autoNumber) {
    fstream binFile;
    binFile.open(fileName + ".dat", ios::binary);
    if (binFile.is_open()) {
        int counter = 0;
        while (binFile.good()) {
            TrafficViolation trafficViolation;
            binFile.read((char *) (&trafficViolation), sizeof(TrafficViolation));
            if (trafficViolation.autoNumber == autoNumber) {
                binFile.seekp(-1 * sizeof(TrafficViolation), ios::end);
                binFile.read((char *) (&trafficViolation), sizeof(TrafficViolation));
                binFile.seekp(counter * sizeof(TrafficViolation), ios::beg);
                binFile.write((char *) (&trafficViolation), sizeof(TrafficViolation));
                break;
            }
            counter++;
        }
        binFile.close();
    }
}

void createFileWithViolationsByAutoNumber(
        string &oldFileName,
        string &newFileName,
        int &autoNumber
) {
    ifstream binFile;
    binFile.open(oldFileName + ".dat", ios::binary);
    ofstream resultBinaryFile;
    resultBinaryFile.open(newFileName + ".dat", ios::binary);
    if (binFile.is_open() && resultBinaryFile.is_open()) {
        TrafficViolation trafficViolation;
        while (binFile.read((char *) (&trafficViolation), sizeof(TrafficViolation))) {
            if (trafficViolation.autoNumber == autoNumber) {
                resultBinaryFile.write((char *) (&trafficViolation), sizeof(TrafficViolation));
            }
        }
        binFile.clear();
        resultBinaryFile.clear();
        if (binFile.good()) {
            binFile.close();
        }
        if (resultBinaryFile.good()) {
            resultBinaryFile.close();
        }
    }
}

void doubleIncreasePunishmentByDateAndArticle(
        string &fileName,
        int &date,
        int &article
) {
    ifstream binFile;
    binFile.open(fileName + ".dat", ios::binary);
    ofstream resultBinFile;
    resultBinFile.open("DoublePunishment" + fileName + ".dat", ios::binary);
    if (binFile.is_open() && resultBinFile.is_open()) {
        TrafficViolation trafficViolation;
        while (binFile.read((char *) (&trafficViolation), sizeof(TrafficViolation))) {
            if (trafficViolation.date == date && trafficViolation.article == article) {
                trafficViolation.punishment *= 2;
            }
            resultBinFile.write((char *) (&trafficViolation), sizeof(TrafficViolation));
        }
        binFile.clear();
        resultBinFile.clear();
        if (binFile.good() && resultBinFile.good()) {
            binFile.close();
            resultBinFile.close();
        }
    }
}
