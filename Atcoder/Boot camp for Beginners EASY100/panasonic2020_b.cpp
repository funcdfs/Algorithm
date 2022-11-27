// LINK: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b
// NAME: B - Bishop, AtCoder - Panasonic Programming Contest 2020
// CODE: https://github.com/fengwei2002, 2022.11.22-21:09:07, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int64_t r = 0, c = 0;
   cin >> r >> c;
	
	if (r == 1 || c == 1) {
		cout << 1 << '\n'; 
		return 0; 
	}
	
   int64_t ans = 0;
   if (c % 2 == 0) {
      int cnt = c / 2;
      c = 2;
      ans = cnt * r;
   } else {
      int cnt = c / 2;
      c = 2;
      ans = cnt * r;
      if (r % 2 == 0) {
         ans += r / 2;
      } else {
         ans += r / 2 + 1;
      }
   }

   cout << ans << '\n';

   return 0;
}

/*



*/