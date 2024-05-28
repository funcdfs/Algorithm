/**
 * author:  https://github.com/funcdfs
 * problem: https://www.acwing.com/problem/content/839/
 * created: 5/13/2024, 12:52:05 AM	
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
    
    int n = 0, m = 0;
    cin >> n >> m;

    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        string a; 
        int b = 0, c = 0;
        cin >> a;
        if (a == "C") {
            cin >> b >> c;
            dsu.merge(b, c);
        } else if (a == "Q1") {
            cin >> b >> c;
            auto x = dsu.same(b, c);
            if (x) cout << "Yes\n";
            else cout << "No\n";
        } else if (a == "Q2") {
            cin >> b;
            cout << dsu.size(b) << endl;
        }
    }
    
    return 0;
}
/*

*/