#include <iostream>
#include <stack>
using namespace std;

// 定义运算符号的优先级关系，0表示低于，1表示等于，2表示高于
int precedence[7][7] = {
    //    +  -  *  /  %  (  )
    /*+*/ {1, 1, 0, 0, 0, 0, 1},
    /*-*/ {1, 1, 0, 0, 0, 0, 1},
    /***/ {1, 1, 1, 1, 1, 0, 1},
    /*/*/ {1, 1, 1, 1, 1, 0, 1},
    /*%*/ {1, 1, 1, 1, 1, 0, 1},
    /*(*/ {0, 0, 0, 0, 0, 0, 2},
    /*)*/ {2, 2, 2, 2, 2, 2, 2}
};

// 定义运算符号的索引，用于在二维数组中查找
int index(char op) {
    switch (op) {
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '%': return 4;
        case '(': return 5;
        case ')': return 6;
        default: return -1;
    }
}

// 比较两个运算符号的优先级，返回0表示低于，1表示等于，2表示高于
int compare(char op1, char op2) {
    return precedence[index(op1)][index(op2)];
}

// 根据运算符号对两个操作数进行计算
int calculate(int num1, int num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '%': return num1 % num2;
        default: return 0;
    }
}

// 将中缀表达式转换为后缀表达式
string infixToPostfix(string infix) {
    stack<char> opStack; // 存储运算符的栈
    string postfix = ""; // 存储后缀表达式的字符串
    for (char c : infix) { // 遍历中缀表达式的每个字符
        if (isdigit(c)) { // 如果是数字，直接添加到后缀表达式中
            postfix += c;
        } else if (c == '(') { // 如果是左括号，压入栈中
            opStack.push(c);
        } else if (c == ')') { // 如果是右括号，弹出栈中的运算符，直到遇到左括号
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop(); // 弹出左括号
            }
        } else { // 如果是运算符，比较它和栈顶运算符的优先级
            while (!opStack.empty() && compare(c, opStack.top()) <= 1) {
                // 如果栈顶运算符的优先级高于或等于它，弹出栈顶运算符并添加到后缀表达式中
                postfix += opStack.top();
                opStack.pop();
            }
            // 将它压入栈中
            opStack.push(c);
        }
    }
    // 将栈中剩余的运算符依次弹出并添加到后缀表达式中
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }
    return postfix;
}

// 计算后缀表达式的值
int evaluatePostfix(string postfix) {
    stack<int> numStack; // 存储操作数的栈
    for (char c : postfix) { // 遍历后缀表达式的每个字符
        if (isdigit(c)) { // 如果是数字，压入栈中
            numStack.push(c - '0');
        } else { // 如果是运算符，弹出栈中的两个操作数，用该运算符对它们进行计算，然后将结果压入栈中
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();
            int result = calculate(num1, num2, c);
            numStack.push(result);
        }
    }
    // 栈中剩余的一个元素就是后缀表达式的值
    return numStack.top();
}

int main() {
    string infix = "2*(3+4)-5/2"; // 中缀表达式
    string postfix = infixToPostfix(infix); // 后缀表达式
    int value = evaluatePostfix(postfix); // 后缀表达式的值
    cout << "中缀表达式: " << infix
