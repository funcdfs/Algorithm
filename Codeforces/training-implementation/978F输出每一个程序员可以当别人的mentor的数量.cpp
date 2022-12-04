// LINK: https://codeforces.com/contest/978/problem/F
// NAME: 978F. Mentors, Codeforces - Codeforces Round #481 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.28-21:05:20, 3000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0; cin >> n >> m; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   vector<int> b = a; 
   sort(b.begin(), b.end()); 
   vector<int> ans(n, 0); 
   for (int i = 0; i < n; i++) {
      int t = distance(begin(b), lower_bound(b.begin(), b.end(), a[i])); 
      ans[i] = t; 
   }
   dbg(ans); 
   
   for (int i = 0; i < m; i++) {
      int x = 0, y = 0; cin >> x >> y; 
      x--, y--; 
      if (a[x] < a[y]) ans[y]--; 
      if (a[y] < a[x]) ans[x]--;
   }
   
   for (int i = 0; i < n; i++) cout << ans[i] << ' '; 
   
   return 0;
}

/*

输出每一个程序员可以当别人的mentor的

*/