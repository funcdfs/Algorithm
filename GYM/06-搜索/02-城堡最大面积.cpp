// URL: https://www.acwing.com/problem/content/1100/
// NAME: 城堡最大面积, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-21 11:59:46

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 4
#define dline() 2
#endif
/*----------------------------------*/

const int N = 55;
int g[N][N];
bool st[N][N];
int n, m;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int bfs(int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    st[x][y] = true;

    int area = 0;
    area++;

    while (que.size()) {
        auto [tx, ty] = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) { 
        // 3 表示存在西墙和北墙，所以 dx 和 dy 要从左手方向开始，顺时针旋转
            int a = tx + dx[i];
            int b = ty + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b] == true) continue;
            if (g[tx][ty] >> i & 1) continue;  // 这个方向存在一个墙的话

            que.push({a, b});
            area++;
            st[a][b] = true;
        }
    }

    return area;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int cnt = 0, area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (st[i][j] == false) {
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << "\n" << area << "\n";

    return 0;
}

/*



*/