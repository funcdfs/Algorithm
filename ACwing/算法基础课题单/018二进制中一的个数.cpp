#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int a[N];
#define LL long long
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

int lowbit(int &a) { return a & -a; }

int main() {
    FastIO int test;
    cin >> test;
    for (int i = 0; i < test; i++) {
        cin >> a[i];
        int ans = 0;
        while (a[i]) {
            a[i] -= lowbit(a[i]);
            ans++;
        }
        if (i > 0) {
            cout << " ";
        }
        cout << ans;
    }
    return 0;
}