/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 21:58:36
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
   
   int x1, y1, x2, y2;
   cin >> x1 >> y1 >> x2 >> y2;

   if (x1 != x2 and y1 != y2 and abs(x1 - x2) != abs(y1 - y2)) {
      cout << -1 << '\n';
   } else {
      if (x1 == x2) {
         cout << x1 + abs(y1 - y2) << ' ';
         cout << y1 << ' ';
         cout << x2 + abs(y1 - y2) << ' ';
         cout << y2 << '\n';
      } else if (y1 == y2) {
         cout << x1 << ' ';
         cout << y1 + abs(x1 - x2) << ' ';
         cout << x2 << ' ';
         cout << y2 + abs(x1 - x2) << '\n';
      } else {
         cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
      }
   }

   return 0;
}