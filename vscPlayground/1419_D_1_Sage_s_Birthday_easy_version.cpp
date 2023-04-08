/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-08 22:53:39
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
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];

   // max buy count
   sort(a.begin(), a.end());
   vector<int> b(0, 0);
   for (int i = n - 1; i >= n / 2; i--) {
      b.push_back(a[i]);
      a.pop_back();
   }
   dbg(b, a);
   vector<int> c(0, 0);
   bool ok = true;
   int idxA = 0, idxB = 0;
   while (idxA < (int)a.size() or idxB < (int)b.size()) {
      if (ok == true and idxB < (int)b.size()) {
         c.push_back(b[idxB]);
         idxB += 1;
      } else if (ok == false and idxA < (int)a.size()) {
         c.push_back(a[idxA]);
         idxA += 1;
      }
      ok = !ok;
   }
   if ((int)b.size() == (int)a.size()) {
      cout << (int)a.size() - 1 << '\n';
   } else {
      cout << (int)a.size() << '\n';
   }
   for (int i = 0; i < (int)c.size(); i++) {
      cout << c[i] << " \n"[i == (int)c.size() - 1];
   }
   return 0;
}