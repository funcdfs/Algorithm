#include <algorithm>
#include <iostream>

using namespace std;

void divide_暴力解法(int n) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int s = 0;
            while (n % i == 0) {
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
}

void divide(int x) {
    // n 中最多只包含一个大于 sqrt n 的质因子
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            cout << i << ' ' << s << endl; // 底数和指数
        }
    }
    // 单独处理： 每个数都有和 1 的质因数分解
    if (x > 1) cout << x << ' ' << 1 << endl; 
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        divide(x);
    }

    return 0;
}


// 从2开始的整数，如果只包含 1 和本身两个约数，就被称为质数，或者素数
// 因为 n 的所有约数都是成对出现的 d|n n/d|n

/*
质因数（素因数或质因子）在数论里是指能整除给定正整数的质数。
除了1以外，两个没有其他共同质因子的正整数称为互质。
因为1没有质因子，1与任何正整数（包括1本身）都是互质。
正整数的因数分解可将正整数表示为一连串的质因子相乘，质因子如重复可以用指数表示。
根据算术基本定理，任何正整数皆有独一无二的质因子分解式 [1]  。只有一个质因子的正整数为质数。

每个合数都可以写成几个质数（也可称为素数）相乘的形式 [2]  ，这几个质数就都叫做这个合数的质因数。
如果一个质数是某个数的因数，那么就说这个质数是这个数的质因数；而这个因数一定是一个质数
*/
