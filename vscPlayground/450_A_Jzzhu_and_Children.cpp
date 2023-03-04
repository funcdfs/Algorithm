/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 00:13:44
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
   
   int n = 0, m = 0;
   cin >> n >> m;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   int mx = 0, k = 0;
   // who is the last child?
   for (int i = 0; i < n; i++) {
      int x = (a[i] - 1) / m + 1;
      if (x >= mx) {
         mx = x;
         k = i;
      }
   }
   cout << k + 1 << '\n';
   return 0;
}