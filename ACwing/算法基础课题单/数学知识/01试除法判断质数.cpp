#include <algorithm>
#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) 
    // 写 i <= x / i 速度最快， i * i <= x 会溢出
    // 写 i <= sqrt(x) 会变慢
        if (x % i == 0) return false;
    return true;
}

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
