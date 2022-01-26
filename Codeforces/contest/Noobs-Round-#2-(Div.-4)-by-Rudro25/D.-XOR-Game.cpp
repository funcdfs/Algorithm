#include <iostream>

using namespace std;
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int main() {
    FastIO

        int test;
    cin >> test;
    while (test--) {
        int a, b;
        cin >> a >> b;
        if ((a ^ b) == (a + b))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}