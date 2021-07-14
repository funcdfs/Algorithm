#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int stk[N], tt;

int main() {
    int m = 0;
    cin >> m;
    while (m--) {
        int x = 0;
        cin >> x;
        while (tt != 0 && stk[tt] >= x) tt--;
        if (tt == 0) {
            cout << "-1 ";
        } else
            cout << stk[tt] << " ";
        stk[++tt] = x;
    }
    return 0;
}

// 输出左侧第一个小于当前元素的元素
// tt 代表 栈中元素的个数，
