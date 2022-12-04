// LINK: https://atcoder.jp/contests/abc157/tasks/abc157_b
// NAME: B - Bingo, AtCoder - AtCoder Beginner Contest 157
// CODE: https://github.com/fengwei2002, 2022.12.03-22:16:00, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   vector<vector<int>> a(3, vector<int>(3, 0)); 
   for (int i = 0; i < 3; i++) 
      for (int j = 0; j < 3; j++)
         cin >> a[i][j];
   int n = 0; 
   cin >> n; 
   vector<int> b(n, 0); 
   for (int i = 0; i < n; i++) cin >> b[i]; 
   
   vector<vector<bool>> st(3, vector<bool>(3, false)); 
   unordered_set<int> s; 
   for (auto& x : b) s.insert(x); 
   
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (s.contains(a[i][j])) {
            st[i][j] = true; 
         }
      }
   }
   
   string ans = "No"; 
   for (int i = 0; i < 3; i++) {
      if (st[i][0] and st[i][1] and st[i][2]) ans = "Yes";
   }
   for (int i = 0; i < 3; i++) {
      if (st[0][i] and st[1][i] and st[2][i]) ans = "Yes";
   }
   if(st[0][0] and st[1][1] and st[2][2]) ans = "Yes";
   if(st[0][2] and st[1][1] and st[2][0]) ans = "Yes";
   
   cout << ans << '\n'; 
   
   return 0;
}

/*



*/