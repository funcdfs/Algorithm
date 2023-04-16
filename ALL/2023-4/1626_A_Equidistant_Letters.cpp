/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 16:36:10
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
      string s = "";
      cin >> s;
      unordered_map<char, int> hs;
      for (auto& c : s) hs[c] += 1;
      string a, b;
      for (auto& [k, v] : hs) {
         if (v == 2) {
            a.push_back(k);
         } else {
            b.push_back(k);
         }
      }
      cout << a << b << a << '\n';
   }
   return 0;
}
/*

*/