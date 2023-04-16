/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 22:41:11
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
  cin.tie(nullptr), ios::sync_with_stdio(false);
  
  int tt = 0;
  cin >> tt;
  while (tt--) {
    int x = 0;
    cin >> x;
    int k = 0;
    for (; x > 0; x -= k) {
      k += 1;
    }
    bool ok = false;
    if (x == 0) {
      ok = true;
    } else {
      for (int i = 1; i <= k; i++) {
        if (x + i + 1 == 0) {
          ok = true;
          break;
        }
      }
    }
    if (ok) {
      cout << k << '\n';
    } else {
      cout << k + 1 << '\n';
    }
  }
  
  return 0;
}
/*
4: 1 2 3
*/