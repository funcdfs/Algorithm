/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/217/problem/A
 * created: 5/12/2024, 11:02:39 PM
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

    int n = 0;
    cin >> n;
    vector<int> x(n, 0), y(n, 0);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x[i] == x[j] or y[i] == y[j]) {
                auto _ = dsu.merge(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            ans += 1;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}
/*

*/