//
// Created by t.shkolnik
//

#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

// Вводная функция
void init() {
    cout << endl;
    cout << "Практическая работа №8. Школьник Татьяна, ИКБО-06-21" << endl;
    cout << "Решение задачи методами динамического программирования." << endl;
}

// Функция валидации ввода количества столбцов
int enterN() {
    int n;
    cout << "Введите количество столбцов N: ";
    cin >> n;
    if(n < 1) {
        cout << "Некорректное значение!";
        enterN();
    }
    return n;
}

// Функция валидации ввода максимального возможного шага
int enterK(int n) {
    int k;
    cout << "Введите максимально возможный шаг K: ";
    cin >> k;
    if(k < 1 || k > n) {
        cout << "Некорректное значение!";
        enterK(n);
    }
    return k;
}

// Функция ввода шансов каждого из столбцов (кроме первого и последнего)
int* enterChances(int* a, int n) {
    cout << "Введите шансы для столбцов (кроме первого и последнего):" << endl;
    for (int i = 1; i < n - 1; i++) {
        cin >> a[i];
    }
    return a;
}

// Функция вывода шансов каждого из столбцов
void printChances(int* a, int n) {
    a[0] = 0;
    a[n - 1] = 0;
    cout << "Список шансов для столбцов: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Функция вычисления минимального шанса встретить лягушку
int calculateFrogChance(int* a, int* ch, int n, int k) {
    int* dp = new int[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        int min_pos = i - 1;
        for (int j = 1; j <= min(i, k); j++) {
            if (dp[i] > dp[i - j]) {
                dp[i] = dp[i - j];
                min_pos = i - j;
            }
        }
        ch[i] = min_pos;
        dp[i] += a[i];
    }

    return dp[n - 1];
}

// Функция вычисления минимального количества прыжков
int calculateMinJumpsCount(vector<int>& jumps, int* ch, int n) {
    int counter = 0;
    int num = n - 1;

    jumps.push_back(num);

    while (num) {
        num = ch[num];
        jumps.push_back(num);
        counter++;
    }

    return counter;
}

// Функция вывода результата программы
void printResult(int frogChance, int minJumpsCount) {
    cout << "Минимальный возможный шанс встретить лягушку: " << frogChance << endl;
    cout << "Минимальное количество прыжков для достижения последнего столбика: " << minJumpsCount << endl;
    cout << "Путь: ";
}

// Функция вывода пути кузнечика
void printWay(vector<int>& jumps) {
    for (int i = jumps.size() - 1; i >= 0; i--) {
        cout << jumps[i] + 1;
        if (i > 0)
            cout << " -> ";
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    init();

    int n, k;
    n = enterN();
    k = enterK(n);

    int* enteredChances = new int[n];
    enteredChances = enterChances(enteredChances, n);

    printChances(enteredChances, n);

    int* chances = new int[n];
    int frogChance = calculateFrogChance(enteredChances, chances, n, k);

    vector<int> jumps;
    int minJumpsCount = calculateMinJumpsCount(jumps, chances, n);

    printResult(frogChance, minJumpsCount);

    printWay(jumps);

    system("pause");
    return 0;
}