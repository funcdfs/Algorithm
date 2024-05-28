// LINK: https://codeforces.com/contest/1253/problem/C
// NAME: 1253C. Sweets Eating, Codeforces - Codeforces Round #600 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.28-20:48:21, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0; 
   cin >> n >> m; 
   vector<int> a(n, 0); 
   vector<int64_t> s(m, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   sort(a.begin(), a.end()); 
   
   int64_t ans = 0; 
   for (int i = 0; i < n; i++) {
      s[i % m] += a[i]; 
      ans += s[i % m]; 
      cout << ans << " \n"[i == n - 1]; 
   }
   
   return 0;
}


/*

1253C吃糖果可以吃到的最小甜度

*/