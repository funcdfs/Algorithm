// LINK: https://codeforces.com/contest/698/problem/A
// NAME: 698A. Vacations, Codeforces - Codeforces Round #363 (Div. 1)
// CODE: https://github.com/fengwei2002, 2022.10.01-17:09:31, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];

   vector f(n + 1, vector<int>(3, 1e9));
   f[0][0] = f[0][1] = f[0][2] = 0;
   for (int i = 1; i <= n; i++) {
      f[i][0] = min({f[i - 1][0], f[i - 1][1], f[i - 1][2]}) + 1;
      if (a[i - 1] == 1 || a[i - 1] == 3) {
         f[i][1] = min(f[i - 1][0], f[i - 1][2]);
      }
      if (a[i - 1] == 2 || a[i - 1] == 3) {
         f[i][2] = min(f[i - 1][0], f[i - 1][1]);
      }
   }

   cout << min({f[n][0], f[n][1], f[n][2]});

   return 0;
}

/*

698A连续的两天不做相同的活动求最少的休息时间


tag: DP
*/