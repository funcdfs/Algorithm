// LINK: https://codeforces.com/contest/1272/problem/D
// NAME: 1272D. Remove One Element, Codeforces - Codeforces Round #605 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.20-20:57:44, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n + 10, 0); 
   for (int i = 1; i <= n; i++) cin >> a[i]; 
   
   vector<int> L(n + 10, 0), R(n + 10, 0); 
   for (int i = 1; i <= n; i++) {
      if (a[i] > a[i - 1]) L[i] = L[i - 1] + 1; 
      else L[i] = 1; 
   }
   for (int i = n; i >= 1; i--) {
      if (a[i] < a[i + 1]) R[i] = R[i + 1] + 1; 
      else R[i] = 1; 
   }
   
   int ans = *max_element(L.begin(), L.end()); 
   for (int i = 2; i < n; i++) {
      if (a[i - 1] < a[i + 1]) {
         ans = max(ans, L[i - 1] + R[i + 1]); 
      }
   }
   cout << ans << '\n'; 
   return 0;
}


/*

1272D可以删除一个元素使得最终的严格递增的子数组长度最长

分别统计以这个数字结尾的最大的长度的数量，和以这个数字开头的最大的长度的数量
记为 L 和 R 

然后 ans 初始化为 L 的最大值或者 R 的最大值
然后遍历一遍整个数组的中间部分 2 \to n - 1 

如果出现了 a[i - 1] < a[i + 1] 的话：
   说明此时删除 a[i] 这个数字之后就会形成一个新的区间 L[i - 1] + R[i + 1] 
   然后维护一下这个最大值即可
*/