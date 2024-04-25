/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 13:14:26
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
    
    int N = 6;
    vector<vector<int>> a(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    int stx, sty, endx, endy;
    cin >> stx >> sty >> endx >> endy;

    const int dx[4] = {0, 1};
    const int dy[4] = {1, 0};

    int ans = 2147483647;
    function<void(int, int, int, int, int)> dfs = [&](int x, int y, int state, int cost, int nowSumCost) {
        dbg(x, y);
        if (x == endx and y == endy) {
            ans = min(ans, nowSumCost);
            return; 
        }
        dbg("HI");
        for (int i = 0; i < 2; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 0 or tx >= N or ty < 0 or ty >= N) continue;
            int thisCost = a[tx][ty] * state;
            int thisState = (thisCost % 4) + 1;
            dbg(tx, ty, thisState, thisCost, nowSumCost + thisCost);
            dfs(tx, ty, thisState, thisCost, nowSumCost + thisCost);
        }
        return;
    };
    // 目的地的数值  乘 源头的状态， 这一步的代价
    // 目的地的状态，这一步的代价，mod 4，再加一。
    
    // 目的地的状态 = (目的地的数值  乘 源头的状态) mod 4, + 1
    dfs(stx, sty, 1, 0, 0);

    cout << ans << endl;

    return 0;
}
/*

*/