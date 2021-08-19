#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) // 写 i <= x / i 速度最快
        if (x % i == 0) return false;
    return true;
}
// 在大于 1 的数字中，如果值存在 1 和其本身两个约数，就被称为质数，素数
// o(sqrt(n))

int main() {
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if (is_prime(x))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}