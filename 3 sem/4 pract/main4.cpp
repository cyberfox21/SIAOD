//
// Created by t.shkolnik
//

#include <windows.h>
#include "tree_node.h"

//Вводная функция, выбор задания
void onboarding() {
    cout << endl;
    cout << "Практическая работа №4. ИКБО-06-21. Школьник Татьяна" << endl;
    cout << endl;
    cout << "1. Создать дерево на основе выражения" << endl;
    cout << "2. Вычислить значение выражения" << endl;
    cout << "3. Вывести дерево" << endl;
    cout << "4. Вывести самый левый узел" << endl;
    cout << "5. Вывести дерево в ширину" << endl;
    cout << endl;
    cout << "Введите команду: ";
}

TreeNode* task1() {
    string expression;
    cout << "Введите выражение: " << endl;
    cin.get();
    getline(cin, expression);
    expression = convertToRPN(expression);
    return convertFromRPN(expression);
}

void task2(TreeNode* tree) {
    if (tree == nullptr) {
        tree = task1();
    }
    cout << calculateResult(tree) << endl;
}

void task3(TreeNode* tree) {
    if (tree == nullptr) {
        tree = task1();
    }
    printTree(tree, 0);
}

void task4(TreeNode* tree) {
    if (tree == nullptr) {
        tree = task1();
    }
    cout << findMostLeftNode(tree) << endl;
}

void task5(TreeNode* tree) {
    if (tree == nullptr) {
        tree = task1();
    }
    printTreeInWidth(tree);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    TreeNode* tree = nullptr;

    int menu = 1;

    while (menu != 0) {
        onboarding();
        cin >> menu;
        switch (menu) {
            case 1: tree = task1(); break;
            case 2: task2(tree); break;
            case 3: task3(tree); break;
            case 4: task4(tree); break;
            case 5: task5(tree); break;
        }
    }

    system("pause");
    return 0;
}