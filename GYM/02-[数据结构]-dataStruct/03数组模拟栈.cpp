#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int stk[N], tt, m;

int main() {
    cin >> m;
    while (m -- ) {
        string op = "";
        int x = 0;

        cin >> op;
        if (op == "push") {
            cin >> x;
            tt++;
            stk[tt] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (op == "query") {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1461831/