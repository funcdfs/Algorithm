/**
 * author:  https://github.com/funcdfs
 * problem: https://atcoder.jp/contests/abc350/tasks/abc350_d
 * created: 5/12/2024, 11:34:59 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

class DSU { // https://github.com/funcdfs
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
    
    int N, M; 
    cin >> N >> M;

    DSU dsu(N);
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A -= 1, B -= 1;
        dsu.merge(A, B);
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        if (dsu.find(i) == i) {
            int s = dsu.size(i);
            ans += (int64_t)s * (s - 1) / 2;
            // 完全联通块中边的数量
        }
    }

    ans -= M;
    // 减去已经存在的边
    cout << ans << endl;
    
    return 0;
}
/*

*/