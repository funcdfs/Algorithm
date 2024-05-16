/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF977E
 * created: 5/13/2024, 12:28:46 AM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

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

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<int> d(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1, v -= 1;
        dsu.merge(u, v);
        d[u] += 1, d[v] += 1;
    }
    vector<bool> st(n, true);
    for (int i = 0; i < n; i++) {
        if (d[i] != 2) {
            st[dsu.find(i)] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i and st[dsu.find(i)] == true) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
问题  1：如何判断一个连通块是否是简单环？
只需要看这个连通块的所有点的度数是不是 2 即可。

问题 2：如何找到每一个连通块？
用并查集维护即可，合并每一条边。
*/