// LINK: https://codeforces.com/contest/977/problem/D
// NAME: 977D. Divide by three, multiply by two, Codeforces - Codeforces Round #479 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.26-11:08:20, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   vector<vector<int>> g(105, vector<int>(0, 0)); 
   vector<int> _next(105, 0); 
   vector<int> deg(105, 0); 
   
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (j == i) continue; 
         if (a[i] % 3 == 0 && a[i] / 3 == a[j]) {
            g[i].push_back(j), _next[i] = j, deg[j]++; 
         } else if (a[i] * 2 == a[j]) {
            g[i].push_back(j), _next[i] = j, deg[j]++; 
         }
      }
   }
   
   int root = 0; 
   for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
         root = i; 
      }
   }
   
   for (int i = 0; i < n; i++) {
      cout << a[root] << " \n"[i == n - 1];  
      root = _next[root]; 
   }
   
   return 0;
}

/*

977D重排序列乘以2或者除以3

*/