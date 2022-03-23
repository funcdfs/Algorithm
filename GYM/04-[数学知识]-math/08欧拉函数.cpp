// 对于正整数 n, 欧拉函数是小于或等于 n 的正整数中与 n 互质的数的数目
// 若 N 个整数的最大公因数是1，则称这 N 个整数互质。

#include <iostream>
using namespace std;

int phi(int x);

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << phi(x) << endl;
    }
    return 0;
}

int phi(int x) {
    int ans = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            ans = ans / i * (i - 1);
            // ans = ans * (1 - i / a)
            // ans = ans - ans * i / a
            while (x % i == 0) x /= i;
        }
        if (x > 1) ans = ans / x * (x - 1);
    }
    return ans;
}
