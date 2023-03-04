/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 01:17
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
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for(int i = 0; i < n; i++) {
         cin >> a[i];
      }
      // 选出两个长度相同的子序列，使得其中一个子序列中的元素相同，另一个子序列内的元素不同 求子序列的最长长度
      unordered_map<int, int> hs;
      for (int i = 0; i < n; i++) {
         hs[a[i]] += 1;
      }
      int maxFreq = 0;
      for (auto& [k, v] : hs) {
         maxFreq = max(maxFreq, v);
      }
      int sz = (int)hs.size();
      int left = sz - 1;
      if (maxFreq > left + 1) {
         dbg("HI");
         cout << left + 1 << '\n';
      } else {
         cout << min(maxFreq, left) << '\n';
      }
   }
   
   return 0;
}


/*



*/
