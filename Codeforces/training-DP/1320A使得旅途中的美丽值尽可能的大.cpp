// LINK: https://codeforces.com/contest/1320/problem/A
// NAME: 1320A. Journey Planning, Codeforces - Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// CODE: https://github.com/fengwei2002, 2022.10.03-13:44:04, 2000 ms

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
   vector<int> b(n, 0); 
   for (int i = 0; i < n; i++) cin >> b[i]; 
   
   map<int, int64_t> sum; 
   for (int i = 0; i < n; i++) {
      sum[i - b[i]] += b[i]; 
   }
   
   int64_t ans = 0; 
   for (auto& [k, v] : sum) {
      ans = max(ans, v); 
   }
   cout << ans << '\n'; 

   return 0;
}


/*

1320A使得旅途中的美丽值尽可能的大


C{i+1} - c{i} = b{ci+1} - b{ci}
对于其变换形式: 
y - by = x - bx 
只需要维护 i - bi 这个数字即可 

对于 b 中的每一个数字 i - bi 都是唯一不变确定的值
所以就可以遍历一遍，然后统计每一个 相同的值的 总和 

只要求每一个选的下标 Ci 是小于 Ci+1 的，所以可以直接遍历求值

*/