/*2021-07-26-23-23*/
#include <algorithm>
#include <cstring>
#include <iostream>]
using namespace std;

const int N = 10;
const int null = 0x3f3f3f3f;

#define LL long long
#define ULL unsigned long long
#define PB push_back
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

char chessBoard[N][N];
bool row[N], col[N];
int n, k;
int ans;

void dfs(int sum) {
    if (sum == k) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (chessBoard[i][j] == '#' && row[i] == false && col[j] == false) {
                row[i] = col[j] = true;
                // chessBoard[i][j] = 'Q';

                // for (int i = 0; i < n; i++) puts(chessBoard[i]);
                //    puts("");
                sum += 1;
                dfs(sum);

                // 从下一个点开始的时候，所有东西都要回到初始状态
                // row[i] = col[j] = false;
                // chessBoard[i][j] = '#';
                sum = 0;
            }
        }
    }
}

void solve() {
    while (1) {
        cin >> n >> k;
        if (n == -1 && k == -1) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char chess;
                cin >> chess;
                chessBoard[i][j] = chess;
            }
        }
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));

        dfs(0);
        printf("%d\n", ans);
        ans = 0;
    }
}

int main() {
    FastIO

    solve();

    return 0;
}

// fw poj 连错误样例都不给，写nm