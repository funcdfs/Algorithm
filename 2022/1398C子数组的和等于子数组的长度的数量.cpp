// LINK: https://codeforces.com/contest/1398/problem/C
// NAME: 1398C. Good Subarrays, Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.10-17:07:40, 2000 ms

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
      int n = 0; 
      cin >> n; 
      string a = string(n, ' '); 
      cin >> a; 
      int64_t ans = 0; 
      map<int, int> m; 
      m[0] = 1; 
      int sum = 0; 
      for (int i = 0; i < n; i++) {
         sum += (a[i] - '0') - 1; 
         ans += m[sum]; 
         m[sum]++; 
      } 
      cout << ans << '\n'; 
   }

   return 0;
}

 
/*

1398C子数组的和等于子数组的长度的数量


区间和等于区间长度的个数

sum[i] - sum[j] = i - j + 1; 
sum[i] - i - 1 = sum[j] - j; 
 
*/