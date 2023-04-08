/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 17:41:34
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      string s = "";
      cin >> n >> s;
      cout << string(n, s[n - 1]) << '\n';
   }
   
   return 0;
}
/*

*/