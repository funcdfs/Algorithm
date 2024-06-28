// link: https://codeforces.com/contest/1861/problem/A A. Prime Deletion
// time: 2024/6/11 09:44:28 https://github.com/funcdfs

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

   string s;
   cin >> s;

   int idx3 = 0, idx1 = 0;

   for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == '3') {
         idx3 = i;
      } else if (s[i] == '1') {
         idx1 = i;
      }
   }

   if (idx3 < idx1 ) {
      cout << format("31\n");
   } else {
      cout << format("13\n");
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
