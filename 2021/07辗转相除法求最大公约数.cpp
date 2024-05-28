#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}

// if d cna div and d can div b
//  d can div a * n + b * n
// a, b 的最大公约数 = (b , a % b) 的最大公约数
