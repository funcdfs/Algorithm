// link: https://codeforces.com/contest/1828/problem/A A. Divisible Array
// time: 2024/6/11 10:37:59 https://github.com/funcdfs

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

auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;

   vector<int> ans(n, 0);

   iota(ans.begin(), ans.end(), 1);
   int64_t sum = accumulate(ans.begin(), ans.end(), int64_t(0));

   int64_t diff = sum % n;
   ans[0] += (int)diff;

   for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int)ans.size() - 1];
   }
   sum = accumulate(ans.begin(), ans.end(), int64_t(0));

   dbg(sum % n);

   
   return;
}

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
