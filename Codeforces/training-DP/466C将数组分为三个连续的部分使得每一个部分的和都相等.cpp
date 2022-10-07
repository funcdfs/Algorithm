// LINK: https://codeforces.com/contest/466/problem/C
// NAME: 466C. Number of Ways, Codeforces - Codeforces Round #266 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.07-11:09:22, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int64_t> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   int64_t sum = accumulate(a.begin(), a.end(), (int64_t)0); 
   
   if (sum % 3) {
      cout << 0 << '\n'; 
      return 0; 
   }
   int64_t avg = sum / 3; 
   vector<int64_t> s(n + 1, 0); 
   for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1]; 
   
   int64_t ans = 0; 
   int firstCnt = 0; 
   for (int i = 1; i <= n; i++) {
      if (i > 1 && i < n && s[i] == avg * 2) {
         ans += firstCnt; 
      } 
      if (s[i] == avg) {
         firstCnt++; 
      }
   }
   cout << ans << '\n'; 
   
   return 0;
}


/*

466C将数组分为三个连续的部分使得每一个部分的和都相等


输出可以分割的方案的总数量
n: 5*1e5



*/