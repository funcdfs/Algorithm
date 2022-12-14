// LINK: https://codeforces.com/contest/474/problem/D
// NAME: 474D. Flowers, Codeforces - Codeforces Round #271 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.12.08-19:52:43, 1500 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int int64_t
const int mod = 1e9 + 7;

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);   
   
   int tt = 0, k = 0; 
   cin >> tt >> k;
   vector<int> f(1e5 + 10, 0); 
   vector<int> s(1e5 + 10, 0); 
   const int N = 1e5 + 2; 
   
   f[0] = 1;
   for (int i = 1; i < N; i++) {
      f[i] = f[i - 1];
      if (i >= k) {
         f[i] += f[i - k];
         if (f[i] >= mod) {
            f[i] -= mod;
         }
      }
   }
   s[0] = 0;
   for (int i = 1; i < N; i++) {
      s[i] = s[i - 1] + f[i];
      if (s[i] > mod) {
         s[i] -= mod;
      }
   }
   while (tt--) {
      int a = 0, b = 0; 
      cin >> a >> b;
      cout << (s[b] - s[a - 1] + mod) % mod; 
      cout << '\n';
   }
   
   return 0;
}

/*

474DLR中每一次只可以吃连续K个蛋糕的字符串的数量


如果当前的字符是 W，那么 当前如果吃并且算数量的话，有两种情况
   如果当前的蛋糕是 R 就可以直接吃   f[i - 1]
   如果当前的蛋糕是 W 就可以从前面的 f[i - k] 转移，但是要附加前面的 k - 1 个连续字符也是 W
*/