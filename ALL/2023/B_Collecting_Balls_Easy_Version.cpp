/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 00:26
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

   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> x(n, 0);
   for (int i = 0; i < n; i++) cin >> x[i];

   int64_t ans = 0;
   for (int i = 0; i < n; i++) {
      if (x[i] > k) {
         ans += x[i] - k;
      } else {
         int minDistance = min((x[i] - 0), (k - x[i]));
         ans += minDistance;
      }
      dbg(ans);
   }
   cout << ans * 2 << '\n';
   return 0;
}

/*

type a placed in (0, i)
type b placed in (k, i)



*/
