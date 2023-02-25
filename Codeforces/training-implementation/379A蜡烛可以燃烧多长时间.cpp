// https://github.com/fengwei2002, 2023.02.18-14:34:26
// https://codeforces.com/contest/379/problem/A
// 379A. New Year Candles, Codeforces - Good Bye 2013

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int a = 0, b = 0;
   cin >> a >> b;
   
   int ans = 0, bad = 0;
   while (a > 0) {
      ans += 1;
      a -= 1;
      bad += 1;
      if (bad == b) {
         bad = 0;
         a += 1;
      }
   }
   
   cout << ans << '\n';
   
   return 0;
}

/*

379A蜡烛可以燃烧多长时间



*/