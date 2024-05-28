/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 19:30:13
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
      cin >> n;
      vector<int> s(n, 0);
      for (int i = 0; i < n; i++) cin >> s[i];
      vector<int> p(n, 0);
      iota(p.begin(), p.end(), 0);
      bool ok = true;
      for (int i = 0; i < n; ) {
         int j = i;
         while (j < n and s[i] == s[j]) {
            j += 1;
         }
         if (j - i == 1) {
            cout << "-1\n";
            ok = false;
            break;
         }
         rotate(p.begin() + i, p.begin() + i + 1, p.begin() + j);
         i = j;
      }
      if (ok == false) continue;
      for (int i = 0; i < n; i++) {
         cout << p[i] + 1 << " \n"[i == n - 1];
      }
   }
   
   return 0;
}
/*

*/