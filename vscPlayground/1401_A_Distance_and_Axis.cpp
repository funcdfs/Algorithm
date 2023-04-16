/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-09 20:15:46
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
      int n = 0, k = 0;
      cin >> n >> k;
      if (k == n) {
         cout << 0 << '\n';
         continue;
      }
      if (k > n) {
         cout << k - n << '\n';
         continue;
      }
      if (n % 2 == k % 2) {
         cout << 0 << '\n';
      } else {
         cout << 1 << '\n';
      }
   }
   
   return 0;
}
/*
if the position of b is placed after a, the abs(dist[o, b] - dist[a, b]) will always
be euqal to a, therefore, when a is not equal to k, there are no feasible solutions
if b is placed at the end

when k is greater than a:
   if the posittion of b is placed between a and o, the abs(dist[o, b] - dist[a, b])
   whil never greater than k, therefore, a can only towards the right side and it's better 
   to move as little as possible. so when it moves to k, b can take 0 to satisfy the condition
   as long as it has not moved to k yet, it does not satisfy the condition
when k is less than a:
   it both a and k have same parity (odd or even), there's no need for movement, otherwise move one bit
*/