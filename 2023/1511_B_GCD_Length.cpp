/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 17:04:36
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
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << 1;
    for (int i = 1; i < a; i++) cout << 0;
    cout << ' ';
    // a is "1" + "0" * (a - 1)
    // b is "1" * (b - (c - 1)) + "0" * (c - 1)
    // c is "1" + "0" * (c - 1)
    for (int i = 0; i < b - c + 1; i++) cout << 1;
    for (int i = 0; i < c - 1; i++) cout << 0;
    cout << '\n';
  }
  
  return 0;
}
/*

*/