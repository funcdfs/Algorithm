/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-12 18:33:59
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int int64_t

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0, m = 0, a = 0;
   cin >> n >> m >> a;
   if (n % a) {
      n -= n % a;
      n += a;
   }
   if (m % a) {
      m -= m % a;
      m += a;
   }
   int l = n / a;
   int r = m / a;
   cout << l * r << '\n';
   return 0;
}
/*

*/