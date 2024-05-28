/**
 * name: 排列数字
 * link: https://www.acwing.com/problem/content/844/
 * time: 2024/5/21 23:11:09 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   iota(a.begin(), a.end(), 1);

   vector<vector<int>> ans;
   vector<int> now;
   vector<bool> st(n, false);

   function<void()> dfs = [&]() -> void {
      if ((int)now.size() == n) {
         ans.push_back(now);
         return;
      }
      for (int i = 0; i < n; i++) {
         if (st[i] == true) continue;
         st[i] = true;
         now.push_back(a[i]);
         dfs();
         now.pop_back();
         st[i] = false;
      }
   };

   dfs();
   for (auto& x : ans) {
      for (auto& y : x) {
         cout << y << ' ';
      }
      cout << endl;
   }
   
   return 0;
}
/*

*/