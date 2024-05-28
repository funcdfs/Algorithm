/**
 * name: B. Just Eat It!
 * link: https://codeforces.com/contest/1285/problem/B
 * time: 2024/5/25 23:07:33 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

class Solution {
  public:
   auto solve_per_case(int _case) -> void {
      dbg(_case);

      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (auto& ai : a) cin >> ai;

      if (count_if(a.begin(), a.end(), [&](auto& x) { return x < 0; }) == 0) {
         cout << format("YES\n");
         return;
      }

      int minVal = *min_element(a.begin(), a.end());
      minVal = abs(minVal);
      if (a[0] > minVal and a.back() > minVal) {
         cout << format("YES\n");
         return;
      } else {
         cout << format("NO\n");
         return;
      }

      return;
   }

  private:
};

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   Solution S;

   for (int _case = 1; _case <= TT; _case++) {
      S.solve_per_case(_case);
   }

   return 0;
}
/*

*/