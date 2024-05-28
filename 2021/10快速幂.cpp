#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p) {
    LL res = 1 % p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * (LL)a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", qmi(a, b, p));
    }

    return 0;
}

// 快速求解，a 的 b 次方模 b 的结果