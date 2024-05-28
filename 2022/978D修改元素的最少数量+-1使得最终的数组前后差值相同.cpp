// LINK: https://codeforces.com/contest/978/problem/D
// NAME: 978D. Almost Arithmetic Progression, Codeforces - Codeforces Round #481 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.26-17:28:18, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   dbg(a); 
   
   auto trans = [](vector<int>& a, vector<int>& b) -> int32_t {
      int diff = b[1] - b[0] ;
      for (int i = 2; i < (int)b.size(); i++) {
         b[i] = b[i - 1] + diff; 
      }
      
      dbg(a, b); 
      
      int moveCnt = 0; 
      for (int i = 0; i < (int)a.size(); i++) {
         if (abs(b[i] - a[i]) <= 1) {
            moveCnt += abs(b[i] - a[i]); 
         } else {
            return 2e9; 
         }
      }
      
      return moveCnt; 
   };
   
   int ans = 2e9; 
   vector<int> b(n, 0); 
   for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
         b[0] = a[0] + i, b[1] = a[1] + j; 
         ans = min(ans, trans(a, b)); 
      }
   }
   
   if (ans == 2e9) {
      cout << -1 << '\n'; 
   } else {
      cout << ans << '\n'; 
   }
   
   return 0;
}

/*

978D修改元素的最少数量+-1使得最终的数组前后差值相同


一个等差数列，可以根据一个首项 a1 和一个公差 d 来唯一的决定
而只要确定了等差数列中的任意的连续两项，那么公差也就决定了

所以 确定了 a1 和 a2 那么这个等差数列就唯一确定了 

一共加一减一和不动三种， 前两项两两组合共有 9 种 
所以也就是 O(9n) 的时间复杂度 


*/