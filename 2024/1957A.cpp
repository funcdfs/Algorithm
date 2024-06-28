// link: https://codeforces.com/contest/1957/problem/A A. Stickogon
// time: 2024/6/11 16:57:58 https://github.com/funcdfs

#pragma region HEAD
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#pragma endregion HEAD

// -------------------------------------------------------------------
auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (auto& ai : a) cin >> ai;
   
   unordered_map<int, int> hs;
   for (auto& x : a) {
      hs[x] += 1;
   }

   int ans = 0;

   for (auto& [k, v] : hs) {
      if (v >= 3) {
         ans += v / 3;
      }
   }

   cout << ans << endl;
   
   return;
}
// -------------------------------------------------------------------

/*

*/

#pragma region MAIN
auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   int testCaseCnt = 0;
   cin >> testCaseCnt;
   for (int _case = 1; _case <= testCaseCnt; _case++) {
      solve(_case);
   }
   return 0;
}
#pragma endregion MAIN
