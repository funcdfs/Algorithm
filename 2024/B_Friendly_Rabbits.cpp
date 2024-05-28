/**
 * name: B - Friendly Rabbits
 * link:
 *https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_b
 * time: 2024/5/28 17:37:02 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   int ans = 0;
   for (int i = 0; i < n; i++) {
      if (i + 1 == a[a[i] - 1]) {
         ans += 1;
      }
   }
   cout << ans / 2 << endl;

   return 0;
}
/*

*/