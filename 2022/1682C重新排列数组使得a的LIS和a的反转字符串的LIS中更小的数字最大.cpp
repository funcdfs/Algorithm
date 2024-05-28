// LINK: https://codeforces.com/contest/1682/problem/C
// NAME: 1682C. LIS or Reverse LIS?, Codeforces - Codeforces Round #793 (Div. 2)
// DATE: 2022.09.27 15:51:48, LIMIT: 256 MB, 1000 ms

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
      for (int i = 0; i < n; i++) cin >> a[i];
      
      unordered_map<int, int> hs; 
      for (int ai : a) hs[ai]++; 
      
      int t = 0, s = 0; 
      for (auto& [k, v] : hs) {
         if (v >= 2) t++; 
      }
      s = hs.size() - t; 
      
      int ans = t; 
      ans += (s % 2 == 0 ? s / 2 : (s - 1) / 2 + 1); 
      cout << ans << '\n'; 
   }

   return 0;
}


/*

1682C重新排列数组使得a的LIS和a的反转字符串的LIS中更小的数字最大



min(lis(a), lis(reversed(a)); 

让 LDS(a) 是最长的严格递减的子序列 (LIS 是最长严格单调递增的子序列)
那么 LIS(a') 就等于 LDS(a); 

一个严格单调递增的直线和一个严格单调递减的直线，他们两个最多只会存在一个交点 
对应到数组中，就是最多只会存在一个共用的 a[index]


如果一个元素 x 的出现的次数 >= 2，那么一个就会在 LIS 中，一个就会在 LDS 中，剩下的都需要丢弃

如果一个元素只出现过一次
那么只会存在三种情况： 
- 只在 LIS 中
- 只在 LDS 中 
- 在 LIS 和 LDS 的交汇点

频次大于等于 2 的可以分布在 LIS 和 LDS 中
频次等于 1 的首先要均匀的分布在 LIS 和 LDS 中
   如果均匀的分布在 LIS 和 LDS 之后，还剩下一个元素，就让这一个元素作为 LIS 和 LDS 的交汇处
*/