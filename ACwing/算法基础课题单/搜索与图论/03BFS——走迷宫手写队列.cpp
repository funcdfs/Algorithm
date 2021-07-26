#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int maze[N][N], weightOfDots[N][N];
PII queueDots[N * N];

int bfs() {
    int hh = 0, tt = 0;
    queueDots[0] = {0, 0};
    memset(weightOfDots, -1, sizeof(weightOfDots));
    weightOfDots[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt) {
        auto temp = queueDots[hh++];

        for (int i = 0; i < 4; i++) {
            int x = temp.first + dx[i], y = temp.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 &&
                weightOfDots[x][y] == -1) {
                weightOfDots[x][y] = weightOfDots[temp.first][temp.second] + 1;
                queueDots[++tt] = {x, y};
            }
        }
    }

    return weightOfDots[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> maze[i][j];

    cout << bfs() << endl;

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1519751/