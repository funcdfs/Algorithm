/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 12:53:17
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
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    // the sum for array is zero
    // choose two indice, i, j, a[i] -= 1, a[j] += 1
    // make all elements equal to zero
    int64_t sum = 0, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans = max(ans, sum);
      sum += a[i];
    }
    cout << ans << '\n';
  }
  
  return 0;
}
/*

*/