//
// Created by t.shkolnik
//

#include<bits/stdc++.h>
#include <windows.h>

using namespace std;

int solution(vector<vector<int>>& triangle, vector<int>& answ) {
    if (triangle.size() == 0) return -1;
    int n = triangle.size();

    map<pair<int, int>, vector<int>> answerMap; //будем хранить путь к ответу для элемента (i, j)

    for (int i = 0; i < n; i++) //мы уже знаем ответ для нижней строки
        answerMap[{n - 1, i}].push_back(triangle[n - 1][i]);

    // начнем строить ответ с последней строчки
    for(int i = n - 2; i > -1; i--) {
        // обходим строчку
        for (int j = 0; j < triangle[i].size(); j++) {
            answerMap[{i, j}].push_back(triangle[i][j]);
            // часть ответа для triangle[i][j]
            // это макcимальный из ответов для triangle[i + 1][j], triangle[i + 1][j + 1] и triangle[i + 1][j - 1]
            int maxCurSum;
            if (j >= 1) {
                maxCurSum = max(triangle[i + 1][j], max(triangle[i + 1][j - 1], triangle[i + 1][j + 1]));
                triangle[i][j] += maxCurSum;
            } else {
                maxCurSum = max(triangle[i + 1][j], triangle[i + 1][j + 1]);
                triangle[i][j] += maxCurSum;
            }

            // скопировали путь, по которому пришли к ответу
            if (maxCurSum == triangle[i + 1][j])
                answerMap[{i, j}].insert(answerMap[{i, j}].begin(),
                                         answerMap[{i + 1, j}].begin(),
                                         answerMap[{i + 1, j}].end());
            else if (maxCurSum == triangle[i + 1][j + 1])
                answerMap[{i, j}].insert(answerMap[{i, j}].begin(),
                                         answerMap[{i + 1, j + 1}].begin(),
                                         answerMap[{i + 1, j + 1}].end());
            else
                answerMap[{i, j}].insert(answerMap[{i, j}].begin(),
                                         answerMap[{i + 1, j - 1}].begin(),
                                         answerMap[{i + 1, j - 1}].end());
        }

    }
    // вернули результат
    answ = answerMap[{0, 0}];
    reverse(answ.begin(), answ.end());
    return triangle[0][0];
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<vector<int>> triangle;
    vector<int> answ;
    int n;
    cout << "Практическая работа №8. Школьник Татьяна, ИКБО-06-21" << "\n";
    cout << "Решение задачи методами динамического программирования." << "\n";
    cout << "Высота треугольника:";
    cin >> n;
    cout << "Введите треугольник: " << "\n";
    for (int i = 1; i <= n; i++) {
        vector<int>row(i);
        for (int j = 0; j < i; j++) cin >> row[j];
        triangle.push_back(row);
    }
    cout << "Результат работы: " << solution(triangle, answ) << "\n";
    cout << "Путь к ответу:" << "\n";
    for (auto value : answ) {
        cout << "-> " << value << " ";
    }
    cout << "\n";
    return 0;
}
