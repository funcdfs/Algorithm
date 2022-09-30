// LINK: https://codeforces.com/contest/1453/problem/B
// NAME: 1453B. Suffix Operations, Codeforces - Codeforces Round #688 (Div. 2)
// DATE: 2022.09.23 12:07:51, LIMIT: 512 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      
      int64_t sum = 0; 
      for (int i = 0; i + 1 < n; i++) {
         sum += abs(a[i] - a[i + 1]); 
      }
      int t = max(abs(a[0] - a[1]), abs(a[n - 2] - a[n - 1])); 
      for (int i = 1; i + 1 < n; i++) {
         t = max(t, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1])); 
      }
      
      cout << sum - t << '\n'; 
   }

   return 0;
}

/*


1453B修改一个数字将后缀中的数字加1或者减1使得所有数字相等


输出最小的修改的次数 
如果不考虑修改一个数字的话， 答案就是所有相邻两数之差的绝对值的和


然后枚举一下修改哪一个数字算一下贡献，例如修改第 x 个数字 


      | a_{x-1} - a_{x} | + | a_{x} - a_{x+1} | 
      | a_{x-1} - a_{x+1} | 



*/