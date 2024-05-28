// LINK: https://codeforces.com/contest/431/problem/C
// NAME: 431C. k-Tree, Codeforces - Codeforces Round #247 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.09-20:36:31, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int f[100][2];
const int mod = 1e9 + 7;

void add(int& a, int b) {
   a += b;
   if (a >= mod) {
      a -= mod;
   }
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, k = 0, d = 0;
   cin >> n >> k >> d;

   f[0][0] = 1;
   f[0][1] = 0;

   for (int i = 1; i <= n; i++) {
      f[i][0] = f[i][1] = 0;
      for (int j = 1; j <= k; j++) {
         if (i - j < 0) break;
         if (j < d) {
            add(f[i][0], f[i - j][0]);
            add(f[i][1], f[i - j][1]);
         } else {
            add(f[i][1], f[i - j][0]);
            add(f[i][1], f[i - j][1]);
         }
      }
   }
   cout << f[n][1] << '\n';

   return 0;
}

/*

431C从k树的根节点开始路径总和为n并且最少存在一个边长大于等于d

let f[n][is]:
   number of ways with length equals to n in k-tree
   where if is = 1
      there is exists edge with length at least d
         if is = 0
      length oof all edges less than d
   initial state f[0][0] = 1

transition:
   iterate all edges which can be first on the way in k-tree
   then problem transform to the same,
   but with less length of the way
*/