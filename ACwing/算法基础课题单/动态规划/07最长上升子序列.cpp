// https://www.acwing.com/activity/content/code/content/1625684/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i] = 1;  // f[i] 最短长度为 1
        for (int j = 1; j <= i; j++) {
            if (a[j] < a[i]) {
                // 考虑前面 i - 1 种情况的最大值
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
