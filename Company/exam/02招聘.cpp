#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int a[N];

int main() {
    int T = 0;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> a[i];

        int ans = 0;
        // 一个人的时候 剩下第 0 号的人

        int j = (n - 1) % m;
        // j 的初始值

        for (int i = 1; i < n; i++) {
            // 每一次都是用 i 推 i + 1 的状态 i 只需要循环到 n - 1 就可以了
            // if (--j < 0) j = m - 1;  // 取模运算可能很慢，使用 if 会加快一些 
            j = (j + m - 1) % m;  
            // k 越来越小, j - 1 可能是负数，变为 j + m - 1
            ans = (ans + a[j]) % i;
        }
        cout << ans << endl;
    }

    return 0;
}