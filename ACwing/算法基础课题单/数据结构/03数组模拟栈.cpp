#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int stk[N], tt;

int main() {
    int m = 0;
    cin >> m;
    while (m--) {
        string op;
        cin >> op;
        int x = 0;
        if (op == "push") {
            stk[tt++] = x;
        } else if (op == "pop") {
            tt--;
        } else if (op == "empty") {
            if (tt == 0)
                cout << "YES";
            else
                cout << "NO";
        } else {
            cout << stk[tt - 1] << endl;
        }
    }
    return 0;
}
