/**
 * name: A. Knapsack
 * link: https://codeforces.com/contest/1446/problem/A
 * time: 2024/5/22 22:41:37 https://github.com/funcdfs
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

   int n = 0, W = 0;
   cin >> n >> W;

   vector<int> w(n, 0);
   vector<int> idx(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> w[i];
      idx[i] = i;
   }

   sort(idx.begin(), idx.end(), [&](int x, int y) { return w[x] <= w[y]; });

   vector<int64_t> preSum(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + w[idx[i - 1]];
   }

   dbg(w);
   dbg(idx);
   dbg(preSum);

   int l = 1, r = n;
   while (l < r) {
      int mid = (l + r) >> 1;
      if (preSum[mid] >= W / 2) {
         r = mid;
      } else {
         l = mid + 1;
      }
   }

   if (preSum[l] > W) {
      cout << format("-1\n");
      return;
   }

   cout << format("{0}\n", l);

   sort(idx.begin(), idx.begin() + l);
   for (int i = 0; i < l; i++) {
      cout << format("{0} ", idx[i] + 1);
   }
   cout << format("\n");

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