/**
 * author: https://github.com/funcdfs
 * created: 2024-04-13 12:17:31
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
    
    int n = 0, m = 0;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    dbg(s);
    vector<vector<bool>> st(n, vector<bool>(m, false));
    queue<pair<int, int>> que;

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    auto flood = [&](int sx, int sy) {
        queue<pair<int, int>> que;
        que.push({sx, sy});
        st[sx][sy] = true;
        while (que.size()) {
            auto [tx, ty] = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int x = dx[i] + tx;
                int y = dy[i] + ty;
                if (x < 0 or x >= n or y < 0 or y >= m) continue;
                if (s[x][y] != 'B' or st[x][y] == true) continue;
                que.push({x, y});
                st[x][y] = true;
            }
        }
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B' and st[i][j] == false) {
                flood(i, j);
                cnt += 1;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}
/*

*/