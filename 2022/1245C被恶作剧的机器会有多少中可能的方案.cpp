// LINK: https://codeforces.com/contest/1245/problem/C
// NAME: 1245C. Constanze's Machine, Codeforces - Codeforces Round #597 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.02-22:18:01, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   const int mod = 1e9 + 7;
   string s = "";
   cin >> s;
   // removeUselessChar(s); // it's error because nan after remove if nn,
   // the situation number will larger

   int n = (int)s.size();

   vector<int> f(n + 1, 0);
   f[0] = f[1] = 1;
   for (int i = 2; i <= n; i++) {
      f[i] = (f[i - 1] + f[i - 2]) % mod;
   } // fib array 
   
   int64_t ans = 1;
   for (int L = 0, R = 0; L < n; L = R) {
      while (R < n and s[R] == s[L]) R++;
      if (s[L] == 'u' or s[L] == 'n') ans = ans * f[R - L] % mod; // find the fib array length
      if (s[L] == 'w' or s[L] == 'm') ans = 0;
   }
   cout << ans % mod << '\n';
   return 0;
}

/*

1245C被恶作剧的机器会有多少中可能的方案

w uu
m nn

定义 f[i] 为以 i 结尾的字符串的方案数量
如果末尾 2 个字符为 nn 或者 uu
方案数当 i == 2 的时候为 2 否则为 f[i - 1] + f[i - 2]
如果末尾的 2 个字符不是 nn 也不是 uu 则方案数量为 f[i - 1]

*/