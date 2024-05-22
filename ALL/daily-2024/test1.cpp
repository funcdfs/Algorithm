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

      if (binary_search(a.begin(), a.end(), 2)) {
         cout << format("-1\n");
      } else {
         cout << format("NO\n");
      }

      dbg("HI");

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