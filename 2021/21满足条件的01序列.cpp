// 给定 n 个 0 和 n 个 1， 排列之后的 2n 长度的序列，
// 能够满足任意前缀序列中 0 的个数，都不少于 1 的个数的序列有多少个

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1e9 + 7;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int a = n * 2, b = n;
    int res = 1;
    for (int i = a; i > a - b; i--) res = (LL)res * i % mod;

    for (int i = 1; i <= b; i++) res = (LL)res * qmi(i, mod - 2, mod) % mod;

    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl;

    return 0;
}
