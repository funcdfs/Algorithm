#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
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
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, m = 0;
   cin >> n >> m;

   DSU dsu(n + 1);
   while (m--) {
      int k = 0;
      cin >> k;
      vector<int> a(k, 0);
      for (int i = 0; i < k; i++) {
         cin >> a[i];
         a[i] -= 1;
      }
      dbg(k, a);
      for (int i = 1; i < k; i++) {
         dsu.merge(a[0], a[i]);
      }
   }

   vector<int> cnt(n, 0);
   for (int i = 0; i < n; i++) {
      cnt[dsu.find(i)] += 1;
   }

   for (int i = 0; i < n; i++) {
      cout << format("{0} ", cnt[dsu.find(i)]);
   }

   return 0;
}
/*

*/