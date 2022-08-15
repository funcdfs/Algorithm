#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool col[N], dg[N], udg[N];  // 同一列，正对角线，反对角线

/*
 * 因为每行只可以出现一个皇后, 就可以枚举对角线和，反对角线，每次枚举哪个位置可以放入皇后
 * 相当于不用遍历全图
 */

void dfs(int u) {
    if (u == n) {
        // 如果皇后数量达标的话，输出这个棋盘，同数字全排列
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) { // 如果当前的行可以放，对角线可以放
            // 反对角线  y = x + k || k = y - x
            // (因为坐标不能为负数，所以加上一个常量 n即可) 正对角线 y = -x + k
            // || k = y + x （是大于 0 的一个值， 不用进行处理）
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            // 进行状态转换
            dfs(u + 1);
            // 迭代

            col[i] = dg[u + i] = udg[n - u + i] = false;
            // 状态回溯, 恢复现场， 与递归之前的代码完全对称
            g[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) g[i][j] = '.';

    dfs(0);

    return 0;
}