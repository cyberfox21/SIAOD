//
// Created by t.shkolnik
//

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

struct TreeNode {
    char value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

// функция создаёт 1 узел дерева
TreeNode* create(char value) {
    TreeNode* node = new TreeNode;
    node->value = value;
    node->rightChild = nullptr;
    node->leftChild = nullptr;
    return node;
}

// функция переводит выражение в вид обратной польской нотации
string convertToRPN(string expression) {
    istringstream ss(expression);
    string element;
    stack<string> stack;
    string rpn = "";
    map<string, int> prioritet = {
            {"(", 1},
            {")", 1},
            {"+", 2},
            {"-", 2},
            {"*", 3},
            {"/", 3}
    };
    while (ss >> element) {
        bool isOperationKeyword = false;
        for (auto& tmp : prioritet) {
            if (tmp.first == element)
                isOperationKeyword = true;
        }
        if (!isOperationKeyword) {
            rpn += " " + element;
        } else {
            if (element == "(") {
                stack.push(element);
            } else if (element == ")") {
                while (!stack.empty() && stack.top() != "(") {
                    rpn += " " + stack.top();
                    stack.pop();
                }
                stack.pop();
            } else {
                while (!stack.empty() && prioritet[stack.top()] >= prioritet[element]) {
                    rpn += " " + stack.top();
                    stack.pop();
                }
                stack.push(element);
            }
        }
    }
    while (!stack.empty()) {
        rpn += " " + stack.top();
        stack.pop();
    }
    return rpn;
}

// функция переводит выражение из обратной польской нотации и строит дерево
TreeNode* convertFromRPN(string rpnExpression) {
    stack<TreeNode*> stackTree;
    TreeNode* treeNode;
    for (int i = 0; i < rpnExpression.size(); i++) {
        if (isdigit(rpnExpression[i])) {
            treeNode = create(rpnExpression[i]);
            stackTree.push(treeNode);
        } else if (
                rpnExpression[i] == '*' or
                rpnExpression[i] == '-' or
                rpnExpression[i] == '+' or
                rpnExpression[i] == '/') {
            treeNode = create(rpnExpression[i]);
            treeNode->rightChild = stackTree.top();
            stackTree.pop();
            treeNode->leftChild = stackTree.top();
            stackTree.pop();
            stackTree.push(treeNode);
        }
    }
    return stackTree.top();
}

// функция ищет самого левого ребёнка(лист) дерева
char findMostLeftNode(TreeNode* rootNode) {
    if (rootNode->leftChild == nullptr)
        return rootNode->value;
    return findMostLeftNode(rootNode->leftChild);
}

// функция выводит дерево повёрнутым на 90 градусов против ч. стр.
void printTree(TreeNode* treeNode, int layer) {
    if (treeNode != nullptr) {
        printTree(treeNode->rightChild, layer + 1);
        for (int i = 1; i <= layer; i++)
            cout << "   ";
        cout << treeNode->value << endl;
        printTree(treeNode->leftChild, layer + 1);
    }
}

// функция считает значение введённого выражения
double calculateResult(TreeNode* node) {
    if (isdigit(node->value)){
        return double(int(node->value) - 48);
    }
    switch (node->value) {
        case '+': return double(calculateResult(node->leftChild)) + double(calculateResult(node->rightChild));
        case '-': return double(calculateResult(node->leftChild)) - double(calculateResult(node->rightChild));
        case '*': return double(calculateResult(node->leftChild)) * double(calculateResult(node->rightChild));
        case '/': return double(calculateResult(node->leftChild)) / double(calculateResult(node->rightChild));
        default: return 0.0;
    }
}

// функция выводит дерево в ширину
void printTreeInWidth(TreeNode* currentNode) {
    if (currentNode->leftChild != nullptr) {
        printTreeInWidth(currentNode->leftChild);
    }
    cout << "Value: " << currentNode->value << endl;
    if (currentNode->rightChild != nullptr) {
        printTreeInWidth(currentNode->rightChild);
    }
}