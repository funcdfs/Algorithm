/**
 * name: A. Learning Languages
 * link: https://codeforces.com/contest/277/problem/A
 * time: 2024/5/17 17:19:33 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

class DSU {  // https://github.com/funcdfs
   private:
    vector<int> f, siz;  // father and size
   public:
    DSU() {}  // DSU dsu(N);
    DSU(int n) { init(n); }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {  // dsu.find(i) == i
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {  // dsu.merge(A, B);
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }  // s = dsu.size(i);
};

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;
    // language from 1 to m
    vector g(n + m + 2, vector<int>(0, 0));
    for (int i = 0; i < n; i++) {
        int k = 0;
        cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; j++) {
            int x = 0;
            cin >> x;
            x -= 1;
            g[i][j] = x;
            g[n + j].push_back(i);
        }
    }
    DSU dsu(n);
    int ans = n - 1;
    int f = 0;
    for 
    vector<bool> st(n + m, false);

    for (int i = 0; i < n + m; i++) {
        for (auto next : g[i]) {
            dsu.merge(next, i);
        }
    }

    int unionCnt = 0;
    for (int i = 0; i < n + m; i++) {
        if (dsu.find(i) == i) {
            unionCnt += 1;
        }
    }
    dbg(unionCnt);

    return 0;
}
/*

每一个员工发散一圈点，求需要连线的最少数量，使得所有员工可以相互连接。

*/