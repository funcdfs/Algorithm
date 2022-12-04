// LINK: https://codeforces.com/contest/988/problem/D
// NAME: D. Points and Powers of Two, Codeforces - Codeforces Round #486 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.27-11:39:00, 4000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   unordered_set<int> s; 
   vector<int> ans(0, 0);
   
   for (int i = 0; i < n; i++) s.insert(a[i]); 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= 30; j++) {
         int d = (1 << j); 
         vector<int> now(0, 0); 
         now.push_back(a[i]); 
         
         if (s.find(a[i] - d) != s.end()) now.push_back(a[i] - d); 
         if (s.find(a[i] + d) != s.end()) now.push_back(a[i] + d);
         if (ans.size() < now.size()) {
            ans = now; 
         }
      }
   }
   
   cout << ans.size() << "\n"; 
   for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int)ans.size() - 1]; 
   }
   return 0;
}

/*

988D找到长度最长的子集使得差值都是2的幂次

当元素的数量大于 3 的时候，例如说为 4 
假设差值为 d 
那么第一个元素和最后一个元素的差值为 3 * d 就无解了

当元素的数量大于 4 的时候，一定存在一个子集的数量为 4，所以也无解了 

最终的方案数量就是 1 2 3 三种情况

*/