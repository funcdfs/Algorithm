// 质数和合数是针对所有大于 2 的数字定义的

#include <algorithm>
#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;  // 判断是否大于 1
    }
    for (int i = 2; i <= x / 2; i++) {
        // 判断从 2 到 i - 1 是否包含 n 的约数，是的话，返回 false， 否则返回 true
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

    // 写 i <= x / i 速度最快， i * i <= x 会溢出
    // 写 i <= sqrt(x) 会变慢

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int x;
        cin >> x;
        if (isPrime(x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}