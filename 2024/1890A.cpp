// link: https://codeforces.com/contest/1890/problem/A A. Doremy's Paint 3
// time: 2024/6/11 11:07:18 https://github.com/funcdfs

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
   vector<int> a(n, 0);
   for (auto& ai : a) cin >> ai;
   
   auto check = [&]() -> bool {
      map<int, int> hs;
      for (auto& x : a) hs[x] += 1;
      if (hs.size() == 1) {
         return true;
      } else if (hs.size() > 2) {
         return false;
      } else {
         int cnt1 = hs.begin()->second;
         int cnt2 = hs.rbegin()->second;
         if (abs(cnt1 - cnt2) <= 1) {
            return true;
         } else {
            return false;
         }
      }
      return true;
   };

   if (check() == true) {
      cout << "Yes\n";
   } else {
      cout << "No\n";
   }
   
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
