// LINK: https://codeforces.com/contest/1380/problem/C
// NAME: 1380C. Create The Teams, Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.02-22:05:09, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0, x = 0; 
      cin >> n >> x; 
      vector<int> a(n, 0); 
      for (int i = 0; i < n; i++) cin >> a[i]; 
      
      sort(a.begin(), a.end(), [](int a, int b) {
         return a > b; 
      }); 
      dbg(a); 
      
      int idx = 0; 
      while (idx < n && a[idx] >= x) idx++; 
      int ans = idx; 
      
      int siz = 0, minVal = 0, t = 0; 
      while (idx < n) {
         siz++; 
         minVal = a[idx]; 
         t = siz * minVal; 
         if (t >= x) {
            ans++; 
            siz = 0; 
         }
         idx++; 
      }
      
      cout << ans << '\n'; 
   }

   return 0;
}


/*

1380C团队中的程序员人数乘团队中最低技能最少为x


求最大的分队的数量
*/