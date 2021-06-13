#include <iostream>
using namespace std;
/*2021-06-08-17-26*/
// http :  // poj.org/problem?id=1321
int main() {
    size_t n = 0;
    size_t k = 0;
    while (true) {
        cin >> n;
        cin >> k;
        cout << n << k;
        if (n == -1 && k == -1) break;
        cout << n << k;
    }

    return 0;
}