// 裴蜀定理：
// 有一对正整数 a, b, 那么一定存在非零整数 x y ，使得 ax + by = (a, b)

// 扩展欧几里得算法，用来求解 x 和 y

#include <algorithm>
#include <iostream>

using namespace std;

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
        int a, b;
        scanf("%d%d", &a, &b);
        int x, y;
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }

    return 0;
}