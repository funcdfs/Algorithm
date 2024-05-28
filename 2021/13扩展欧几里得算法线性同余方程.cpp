// 例如数据 ：
// 4 3 5 ,  4x 同余 3 (mod 5) ，求 x 等于多少  x 可以等于 2， 或者 7，
// 只要输出任意一个在 int 范围内的数字就可以

#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, m;
        scanf("%d%d%d", &a, &b, &m);

        int x, y;
        int d = exgcd(a, m, x, y);
        if (b % d)
            puts("impossible");
        else
            printf("%d\n", (LL)b / d * x % m);
    }

    return 0;
}