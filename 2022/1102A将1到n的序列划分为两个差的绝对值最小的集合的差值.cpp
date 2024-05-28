// LINK: https://codeforces.com/contest/1102/problem/A
// NAME: 1102A. Integer Sequence Dividing, Codeforces - Codeforces Round #531 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.12-15:25:39, 1000 ms

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
   
   int x = n % 4;
   dbg(n, x);
   if (x == 1 || x == 2) {
      cout << 1 << '\n';
   } else if (x == 0 || x == 3) {
      cout << 0 << '\n';
   }
   
   return 0;
}

/*

1102A将1到n的序列划分为两个差的绝对值最小的集合的差值

n and n - 3 == n - 1 and n - 2

*/