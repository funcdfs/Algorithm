/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 20:00:17
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
      // 使用双端队列重新排列使得字典序最小
      deque<int> que;
      que.push_back(a[0]);
      for (int i = 1; i < n; i++) {
         if (a[i] < que.front()) {
            que.push_front(a[i]);
         } else {
            que.push_back(a[i]);
         }
      }
      while (que.size()) {
         cout << que.front() << ' ';
         que.pop_front();
      }
      cout << '\n';
   }
   
   return 0;
}
/*

*/