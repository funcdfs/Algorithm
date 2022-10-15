// LINK: https://codeforces.com/contest/1304/problem/C
// NAME: 1304C. Air Conditioner, Codeforces - Codeforces Round #620 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.15-14:00:02, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int q, n, m; 
vector<int> t, l, r; 
void solve() {
   cin >> n >> m; 
   t.resize(n), l.resize(n), r.resize(n); 
   int lastTime = 0; 
   for (int i = 0; i < n; i++) cin >> t[i] >> l[i] >> r[i]; 
   int x = m, y = m; 
   for (int i = 0; i < n; i++) {
      int diff = t[i] - lastTime; 
      x -= diff; 
      y += diff; 
      x = max(x, l[i]); 
      y = min(y, r[i]); 
      if (x > y) {
         cout << "NO\n"; 
         return; 
      } 
      lastTime = t[i]; 
   }
   cout << "YES\n"; 
   return; 
}

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   cin >> q; 
   while (q--) {
      solve(); 
   }
   return 0;
}

/*

1304C是否可以让所有的顾客都在进入餐厅的一瞬间对温度满意


*/