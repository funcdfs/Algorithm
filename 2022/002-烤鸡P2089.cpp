// Problem: P2089 烤鸡
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2089
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// date: 2022-01-25 20:51:21

/*
 @ KONNG
 @ https://github.com/fengwei2002/Algorithm
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define INF 0x10f10f10f10f
typedef long long ll;

using namespace std;

vector<int> path;
vector<vector<int>> ans;

void dfs(int totalSum, int index, int nowSum, vector<int>& path) {
    if (index >= 10) {
        int sum = accumulate(path.begin(), path.begin() + 10, 0);
        if (sum == totalSum) {
            ans.push_back(path);
        }
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (nowSum + i > totalSum) break;
        path.push_back(i);
        dfs(totalSum, index + 1, nowSum + i, path);
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    path.resize(0);

    dfs(n, 0, 0, path);

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++) {
        for (int j = 0; j < 10; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}