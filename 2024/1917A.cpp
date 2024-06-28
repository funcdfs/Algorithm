// link: https://codeforces.com/contest/1917/problem/A A. Least Product
// time: 2024/6/12 11:31:40 https://github.com/funcdfs

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
   for (auto& x : a) cin >> x;

   

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
