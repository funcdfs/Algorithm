#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void eval() {
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        auto c = str[i];
        if (isdigit(c)) {
            // 如果当前是数字的话
            int x = 0, j = i;
            // 从 i 开始将这一个数字读完
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            // 因为跳出循环的时候多了一个 j++， 所以 i = j - 1 
            i = j - 1;
            // 数字放入数字栈中
            num.push(x);
        } else if (c == '(')
            // 如果是左括号的话直接放入操作符栈
            op.push(c);
        else if (c == ')') {
            // 如果是右侧括号的话，说明可以有一个阶段性的结果了，
            // 一直将不是右侧括号的操作符弹出，并且配合两个数字来进行计算
            while (op.top() != '(') eval();
            // 将右侧括号从操作符栈中弹出
            op.pop();
        } else {
            // 除了数字和左右括号就是进行加减乘除的处理了
            //如果栈顶操作符优先级大于 c 的时候，进行计算，（因为栈顶可能垒了一堆乘法，所以需要 while 而不是 if ） 
            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            // 如果当前元素的优先级比栈顶元素还大的话，放入操作符栈中
            op.push(c);
        }
    }
    // 将操作符栈清空，每清空一次就就散一次
    while (op.size()) eval();
    // 经过运算之后 nums 栈顶就是表达式的结果了
    cout << num.top() << endl;
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1481222/