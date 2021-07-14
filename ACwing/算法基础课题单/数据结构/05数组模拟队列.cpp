#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh, tt;

int main() {
    cin >> m;

    while (m--) {
        string op;
        int x;

        cin >> op;
        if (op == "push") {
            cin >> x;
            q[tt++] = x;
        } else if (op == "pop")
            hh++;
        else if (op == "empty")
            cout << (hh <= tt - 1 ? "NO" : "YES") << endl;
        else
            cout << q[hh] << endl;
    }

    return 0;
}