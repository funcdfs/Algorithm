/**
 * name: A. Chess For Three
 * link: https://codeforces.com/contest/1973/problem/A
 * time: 2024/5/21 23:04:43 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto solve(int _case) -> void {
   dbg(_case);
   
   int p1, p2, p3;
   cin >> p1 >> p2 >> p3;

   auto check = [&]() -> bool {
      int s = p1 + p2 + p3;
      int maxVal = max({p1, p2, p3});
      if (s % 2) {
         return false;
      } else {
         int x = min({s - maxVal, s / 2});
         cout << format("{0}\n", x);
         return true;
      }
      return true;
   };

   if (check() == false) {
      cout << format("-1\n");
      return;
   }
   
   return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }

   return 0;
}
/*

*/