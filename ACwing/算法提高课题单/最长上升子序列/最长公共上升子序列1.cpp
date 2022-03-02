// Problem: 最长公共上升子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/274/
// date: 2022-02-18 22:19:22
// Memory Limit: 64 MB
// Time Limit: 1000 ms


/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 3000;
int n;
int a[N], b[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];          // 右半边
            if (a[i] == b[j]) {             // 如果 a[i] != b[j] 的话，左边就是空集
                int maxV = 1;
                for (int k = 1; k < j; k++) {
                    if (b[k] < b[j]) {      // 因为以 b[j] 结尾
                        maxV = max(maxV, f[i - 1][k] + 1);
                    }
                }
                f[i][j] = max(f[i][j], maxV);
            }          

        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}