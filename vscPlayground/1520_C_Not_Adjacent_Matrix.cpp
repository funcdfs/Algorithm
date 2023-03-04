/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 22:07:33
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      if (n == 1) {
         cout << 1 << '\n';
         continue;
      }
      if (n == 2) {
         cout << -1 << '\n';
         continue;
      }

      // 构造一个 n * n 的矩阵，使得相邻的两个格子中填写的数字不相邻
      vector<int> a(0, 0), b(0, 0);
      for (int i = 1; i <= n * n; i++) {
         if (i & 1) a.push_back(i);
         else b.push_back(i);
      }
      dbg(a, b);
      a.insert(a.end(), b.begin(),b.end());
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cout << a[i * n + j] << ' ';
         }
         cout << '\n';
      }
   }
   
   return 0;
}