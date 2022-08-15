#include <bits/stdc++.h>

#include <functional>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

int n = 0;
int maxPathSum = 0;
vector<int> w; 

void dfs(int u, int sum) {
    sum += w[u];
    if (u * 2 > n && u * 2 + 1 > n) {
        maxPathSum = max(maxPathSum, sum);
        return;
    }

    if (u * 2 <= n) dfs(u * 2, sum);
    if (u * 2 + 1 <= n) dfs(u * 2 + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    w.resize(n + 1); 
    for (int i = 1; i <= n; i++) cin >> w[i];

    dfs(1, 0);

    cout << maxPathSum << endl;

    return 0;
}

/*



*/