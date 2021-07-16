#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N], tt;

int main() {
    int m = 0;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        int x = 0;
        if (op == "push") {
            cin >> x;
            stk[++tt] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1461831/