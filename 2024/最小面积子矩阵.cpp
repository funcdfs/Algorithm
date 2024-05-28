/**
 * author: https://github.com/funcdfs
 * created: 2024-04-10 12:38:49
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    // 处理每一行的前缀和 O(n*m)

    // 然后枚举每一个矩形的左上角和右下角，共 100*100=10000
    // 然后每一次使用前缀和的时候最多遍历 100*2 次 100 0000

    // 直接暴力
    vector a(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector s(n + 1, vector<int64_t>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] =
                a[i - 1][j - 1] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    auto cal = [&](int x1, int y1, int x2, int y2) {
      int64_t ans = s[x2][y2] 
         - s[x1 - 1][y2] 
         - s[x2][y1 - 1] 
         + s[x1 - 1][y1 - 1]; 
        return ans;
    };

    int ans = numeric_limits<int32_t>::max();

    for (int stx = 1; stx <= n; stx++) {
        for (int sty = 1; sty <= n; sty++) {
            for (int edx = stx; edx <= n; edx += 1) {
                for (int edy = sty; edy <= m; edy += 1) {
                    int x = cal(stx, sty, edx, edy);
                    if (x >= k) {
                        ans = min(ans, (edx - stx + 1) * (edy - sty + 1));
                    }
                }
            }
        }
    }

    if (ans == numeric_limits<int32_t>::max()) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
/*

*/