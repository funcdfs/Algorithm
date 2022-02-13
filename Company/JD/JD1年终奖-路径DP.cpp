class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        // f[i][j] 表示 可以在 board[i][j] 位置拿到的最大礼物
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        f[0][0] = board[0][0];
        for (int i = 1; i < m; i++) f[0][i] = f[0][i - 1] + board[0][i];
        for (int i = 1; i < n; i++) f[i][0] = f[i - 1][0] + board[i][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                f[i][j] += board[i][j];
            }
        }
        return f[n - 1][m - 1];
    }
};

// https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab