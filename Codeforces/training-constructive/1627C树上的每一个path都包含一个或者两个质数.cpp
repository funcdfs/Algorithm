// LINK: https://codeforces.com/contest/1627/problem/C
// NAME: 1627C. Not Assigning, Codeforces - Codeforces Round #766 (Div. 2)
// DATE: 2022.09.25 10:28:47, LIMIT: 256 MB, 2500 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   function<void()> solve = [&]() {
      int n = 0; 
      cin >> n; 
      vector<vector<pair<int, int>>> g(n); 
      for (int i = 0; i < n - 1; i++) {
         int u = 0, v = 0; 
         cin >> u >> v; 
         u--, v--; 
         g[u].push_back({v, i}); 
         g[v].push_back({u, i}); 
      }
      
      for (int i = 0; i < n; i++) {
         if (g[i].size() > 2) {
            cout << -1 << '\n'; 
            return; 
         }
      }
      
      vector<int> ans(n - 1, 0); 
      
      int x = 0; 
      while (g[x].size() == 2) x++; 
      int value = 2; 
      while (x != -1) {
         int node = -1; 
         for (pair<int, int>& e : g[x]) {
            if (ans[e.second] == 0) {
               ans[e.second] = value; 
               node = e.first; 
               break; 
            }
         }
         x = node; 
         value = 5 - value; 
      }
      for (int i = 0; i < n - 1; i++) {
         cout << ans[i] << " \n"[i == n - 2]; 
      }
   };

   int tt = 0;
   cin >> tt;
   while (tt--) {
      solve(); 
   }

   return 0;
}

/*

1627C树上的每一个path都包含一个或者两个质数

*/