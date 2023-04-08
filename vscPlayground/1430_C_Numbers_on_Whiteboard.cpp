/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 11:27:04
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
      function<bool(int&, int&)> maxPQCmp = [](int& a, int& b) {
         return a < b;
      };
      priority_queue<int, vector<int>, function<bool(int&, int&)>> maxPQ(maxPQCmp);
      for (int i = 0; i < n; i++) {
         maxPQ.push(i + 1);
      }
      vector<pair<int, int>> ans;
      while (maxPQ.size() >= 2) {
         auto x = maxPQ.top();
         maxPQ.pop();
         auto y = maxPQ.top();
         maxPQ.pop();
         ans.push_back({x, y});
         maxPQ.push((x + y + 1) / 2);
      }

      cout << maxPQ.top() << '\n';
      for (auto& item : ans) {
         cout << item.first << ' ' << item.second << '\n';
      }
   }
   
   return 0;
}
/*

*/