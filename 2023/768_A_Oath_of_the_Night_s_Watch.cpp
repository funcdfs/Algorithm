/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 14:00:06
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

   int maxVal = *max_element(a.begin(), a.end());
   int minVal = *min_element(a.begin(), a.end());
   int cntMax = count(a.begin(), a.end(), maxVal);
   int cntMin = count(a.begin(), a.end(), minVal);

   if (maxVal == minVal) {
      cout << n - cntMax << '\n';
   } else {
      cout << n - cntMax - cntMin << '\n';
   }

   return 0;
}
/*

*/