/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-03 23:39:50
**/

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
      string s, t;
      cin >> s >> t;
      int k = (int)s.size() * (int)t.size() / gcd((int)s.size(), (int)t.size());
      string rs, rt;
      for (int i = 0; i < k; i += (int)s.size()) {
         rs += s;
      }
      for (int i = 0; i < k; i += (int)t.size()) {
         rt += t;
      }
      if (rs == rt) {
         cout << rs << '\n';
      } else {
         cout << -1 << '\n';
      }
   }
   

   return 0;
}