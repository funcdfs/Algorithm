// LINK: https://codeforces.com/contest/1327/problem/C
// NAME: 1327C. Game with Chips, Codeforces - Educational Codeforces Round 84
// (Rated for Div. 2) DATE: 2022.09.21 18:12:13, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    vector<pair<int, int>> chips;
    for (int i = 0; i < k; i++) {
        int sx = 0, sy = 0;
        cin >> sx >> sy;
        chips.push_back({sx, sy});
    }

    vector<pair<int, int>> goals;
    for (int i = 0; i < k; i++) {
        int fx = 0, fy = 0;
        cin >> fx >> fy;
        goals.push_back({fx, fy});
    }

    dbg(chips);
    dbg(goals);

    string ans = string(n - 1, 'U');
    ans += string(m - 1, 'L');
    for (int i = 0; i < n; i++) {
        ans += string(m - 1, "RL"[i % 2]);
        if (i != n - 1) {
            ans += 'D';
        }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}

/*

1327C. Game with Chips

2 * n * m 次操作之后，使得所有的 clips 遍历过属于自己的 goals

n - 1 次 up 使得所有的方块移动到第一行上
m - 1 次 left 使得所有的方块移动到第一列第一行上

然后现在的任务就是在 (1, 1) 开始的 n * m 的地图上面，找到一个路径，遍历所有的
Pairs

n-1 + m-1
n+m-2

(m-1)*n

n*m - n + n + m - 2
n * m + m - 2

2 * n * m <<< PK >>> n * m + m - 2
n * m << PK >> m - 2

n >= 1
所以 n * m > m - 2


*/