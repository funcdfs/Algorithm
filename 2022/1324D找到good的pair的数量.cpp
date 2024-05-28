// LINK: https://codeforces.com/contest/1324/problem/D
// NAME: 1324D. Pair of Topics, Codeforces - Codeforces Round #627 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.06-22:43:04, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0), b(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   for (int i = 0; i < n; i++) cin >> b[i]; 
   
   vector<int> c(n, 0); 
   for (int i = 0; i < n; i++) {
      c[i] = a[i] - b[i]; 
   }
   sort(c.begin(), c.end());
   
   int64_t ans = 0; 
   for (int i = 0; i < n; i++) {
      if (c[i] <= 0) continue; 
      int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin(); 
      ans += i - pos; 
   }
   
   cout << ans << '\n'; 
   
   return 0;
}


/*

1324D找到good的pair的数量


式子两边同时拥有 i 和 j 
   a[i] + a[j] > b[i] + b[j]
   
所以可以移项，然后 a[i] - b[i] > b[j] - a[j] 
   (a[i] - b[i]) + (a[j] - b[j]) > 0 
build the array c where c[i] == a[i] - b[i] 
then sort this array 

the problem is to find the number of pairs i < j 
   such that ci + cj > 0 
   
因为加和大于 0 所以这对候选人中至少有一个是正数
所以 ci < 0 的情况直接跳过即可

对于一个大于 0 的 ci 需要计算 ci + cj > 0 的 j 的数量 

也就是 cj > -ci, cj >= -ci + 1
要找的是满足这个条件的最左侧的 j （越往左侧 c 的值越小） 
   lower_bound
*/