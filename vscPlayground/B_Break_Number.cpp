/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 22:07
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
   int ans = 0;
   while (n) {
      ans += 1;
      n >>= 1;
   }
   cout << (1 << (ans - 1)) << '\n';
   return 0;
}

/*



*/
