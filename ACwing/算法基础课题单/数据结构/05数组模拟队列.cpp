#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh, tt = -1;
// tt 代表栈顶， tt 等于 -1 的时候栈中元素为空
// hh 的值代表要弹出元素的边界

int main() {
    cin >> m;

    while (m--) {
        string op;
        int x;

        cin >> op;
        if (op == "push") {
            cin >> x;
            q[++tt] = x;
        } else if (op == "pop")
            hh++;
        else if (op == "empty")
            cout << (hh <= tt ? "NO" : "YES") << endl;
        else
            cout << q[hh] << endl;
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1461916/