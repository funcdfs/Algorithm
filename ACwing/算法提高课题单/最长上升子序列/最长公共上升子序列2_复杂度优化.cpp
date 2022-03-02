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
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            // 求右半部分，不包含 a[i]
            
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            // 如果左半侧存在，则更新 f[i][j] 
            
            if (b[j] < a[i]) maxv = max(maxv, f[i][j] + 1);
            // 如果序列仍然上升，则更新 1 到 j - 1 中的最大值
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    
    cout << ans << endl;
    
    return 0;
}