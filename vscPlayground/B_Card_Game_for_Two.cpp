/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 00:49
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
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end(), [](int x, int y) { return x > y; });
   int64_t alice = 0, bob = 0;
   for (int i = 0; i < n; i++) {
      if (i % 2) {
         bob += a[i];
      } else {
         alice += a[i];
      }
   }
   cout << alice - bob;
   return 0;
}

/*



*/
