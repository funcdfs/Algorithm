/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 12:41:19
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
    vector<pair<int, int>> ans;
    int idx = -1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        idx = i;
        ans.push_back({1, i + 1}); // connect 1 to the i node, have differenet districts
      }
    }
    if (idx == -1) {
      cout << "NO\n";
      continue;
    }
    for (int i = 1; i < n; i++) {
      if (a[i] == a[0]) {
        ans.push_back({idx + 1, i + 1}); // connect idx to the node that same as original node
      }
    }
    cout << "YES\n";
    for (auto& [x, y] : ans) {
      cout << x << ' ' << y << '\n';
    }
  }
  
  return 0;
}
/*

*/