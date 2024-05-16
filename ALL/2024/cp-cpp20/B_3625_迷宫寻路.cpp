/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/B3625
 * created: 5/8/2024, 12:19:47 PM	
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0, m = 0;
    cin >> n >>m;
    vector a(n, vector<char>(m, ' '));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m;j++)cin >>a[i][j];
    }
    
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    auto check = [&]() -> bool {
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<vector<bool>> st(n, vector<bool>(m, false));
        st[0][0] = true;

        while (que.size()) {
            auto [tx, ty] = que.front();
            que.pop();

            for (int i = 0; i < 4; i++) {
                int x = tx + dx[i];
                int y = ty + dy[i];
                if (x < 0 or x >= n or y < 0 or y >= m) continue;
                if (a[x][y] == '#') continue;
                que.push({x, y});
                st[x][y] = true;
            }
        }

        if (st[n - 1][m - 1] == true) return true;
        return false;
    };



    if (check()) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}
/*

*/