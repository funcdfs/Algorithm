// LINK: https://codeforces.com/contest/1547/problem/A
// NAME: 1547A. Shortest Path with Obstacle, Codeforces - Codeforces Round #731 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.05-15:08:41, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

struct P {
   int x, y; 
};

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      P A, B, F; 
      cin >> A.x >> A.y; 
      cin >> B.x >> B.y; 
      cin >> F.x >> F.y; 
      int ans = abs(A.x - B.x) + abs(A.y - B.y); 
      if (A.x == F.x and B.x == F.x and (A.y - F.y) * (B.y - F.y) < 0) {
         ans += 2; 
      }
      if (A.y == F.y and B.y == F.y and (A.x - F.x) * (B.x - F.x) < 0) {
         ans += 2; 
      }
      // is the F in the middle, (A.x - F.x) * (B.x - F.x) < 0
      cout << ans << '\n';
   }
   
   return 0;
}

/*

1547A只可以走直线的AB间的最短路不可以走F

*/