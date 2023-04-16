/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-12 18:47:07
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

struct Vec {
   int x, y, z;
   Vec() { this->x = 0, this->y = 0, this->z = 0; }
};

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   vector<Vec> vecs(n);
   for (int i = 0; i < n; i++) {
      Vec& v = vecs[i];
      cin >> v.x >> v.y >> v.z;
   }
   int X = 0, Y = 0, Z = 0;
   for (auto v : vecs) {
      X += v.x, Y += v.y, Z += v.z;
      dbg(X, Y, Z);
   }
   if (X == 0 and Y == 0 and Z == 0) cout << "YES\n";
   else cout << "NO\n";
   return 0;
}
/*

*/