/**
 * name: C. Find B
 * link: https://codeforces.com/contest/1923/problem/C
 * time: 2024/5/22 23:01:32 https://github.com/funcdfs
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
   
   int n = 0, q = 0;
   cin >> n >> q;

   vector<int> c(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> c[i];
   }

   for (int qi = 0; qi < q; qi++) {
      int l = 0, r = 0;
      cin >> l >> r;

      
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