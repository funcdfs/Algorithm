/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 22:34
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int func(int x, int y, int z) {
   if (x % 2 == 1 || y % 2 == 1 || z % 2 == 1) {
      return 0;
   }
   if (x == y and x == z) {
      return -1;
   }
   return func((y + z) / 2, (x + z) / 2, (x + y) / 2) + 1;
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int a = 0, b = 0, c = 0;
   cin >> a >> b >> c;
   cout << func(a, b, c);
   return 0;
}


/*



*/
