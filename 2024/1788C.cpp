/**
 * name: C. Matching Numbers
 * link: https://codeforces.com/contest/1788/problem/C
 * time: 2024/5/22 11:54:42 https://github.com/funcdfs
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

   int n = 0;
   cin >> n;

   if (n % 2 == 0) {
      cout << format("No\n");
      return;
   }
   
   

   return;
}


array<int, 4> dx = {-1, 1, 0, 0};
array<int, 4> dy = {0, 0, -1, 1};

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