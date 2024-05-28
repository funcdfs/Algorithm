/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 23:14:18
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
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   // 选出来三个数字构成一个三角形
   sort(a.begin(), a.end());
   for (int i = 2; i < n; i++) {
      if (a[i] < a[i - 1] + a[i - 2]) {
         return cout << "YES", 0;
      }
   }
   cout << "NO";
   return 0;
}