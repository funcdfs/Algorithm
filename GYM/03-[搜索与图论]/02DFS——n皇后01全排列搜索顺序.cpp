

#include <iostream>

using namespace std;

const int N = 10;

int n;
bool row[N], col[N], diagonal[N * 2], antiDiagonal[N * 2];

char chessBoard[N][N];

void dfs(int x, int y, int sum) {
    if (sum > n) return;
    if (y == n) y = 0, x++;
    if (x == n) {
        if (sum == n) {
            for (int i = 0; i < n; i++) puts(chessBoard[i]);
            puts("");
        }
        return;
    }

    chessBoard[x][y] = '.';

    dfs(x, y + 1, sum);

    if (!row[x] && !col[y] && !diagonal[x + y] && !antiDiagonal[x - y + n]) {
        row[x] = col[y] = diagonal[x + y] = antiDiagonal[x - y + n] = true;
        chessBoard[x][y] = 'Q';

        dfs(x, y + 1, sum + 1);

        chessBoard[x][y] = '.';
        row[x] = col[y] = diagonal[x + y] = antiDiagonal[x - y + n] = false;
    }
}

int main() {
    cin >> n;
    dfs(0, 0, 0);
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1519746/