#include <algorithm>
#include <iostream>
const int N = 110;
int n;
int a[N], f[N], g[N];
int ans;
using namespace std;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
    }

    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i] > a[j]) g[i] = max(g[i], g[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i] + g[i] - 1);
    cout << n - ans << endl;

    return 0;
}