/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-09 00:04:38
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
   
   int n = 0, a = 0;
   cin >> n >> a;
   vector<int> t(n, 0);
   for (int i = 0; i < n; i++) cin >> t[i];
   int cnt = count(t.begin(), t.end(), 1);
   if (t[a - 1] == 1) cnt -= 1;
   cout << cnt;

   return 0;
}
/*

*/