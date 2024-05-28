// LINK: https://codeforces.com/contest/1513/problem/B
// NAME: 1513B. AND Sequences, Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// DATE: 2022.09.25 20:49:06, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int modulo = 1e9 + 7; 

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0; 
      cin >> n; 
      vector<int> a(n, 0); 
      for (int i = 0; i < n; i++) cin >> a[i]; 
      
      int x = a[0]; 
      for (int i = 1; i < n; i++) x = x & a[i]; 
      int cnt = count_if(a.begin(), a.end(), [x](int ai) { return ai == x; }); 
      // 左端点有 cnt 种
      // 右端点有 cnt - 1 种
      // 中间的所有点有 n - 2 个，中间所有点的不同的排列共有 {n - 2}! 种
      int64_t ans = int64_t(cnt) * (cnt - 1) % modulo; 
      for (int i = n - 2; i >= 1; i--) {
         ans = ans * i % modulo; 
      } 
      cout << ans << '\n'; 
   }

   return 0;
}


/*

1513B构造排列前半部分的与的结果和后半部分的与的结果相同


a1 = a2 & a3 & a4 ... & an 
an = a1 & a2 & a3 ... & an-1

相同数字与之后结果不变 

a1 = a1 & a2 & a3 ... & an
an = a1 & a2 & a3 ... & an 

所以只要 a1 和 an 是等于所有数字 & 起来的，那么就可以分成两个部分

a1 & a2 = a1 & a2 & a3 ... an 

因为 a1 是所有的 1 合起来的集合所以存在，后面随便跟数字，同理，右边也是 an 存在就可以随便跟数字 


对于一个好的排列 虽然可能出现

1100 0011 == 1100 0011 

但是因为 good 的条件是从 

a1 = a2 .. an
到
a1 .. an-1 = an

所以上述结论成立， 因为 a1 和 an 总是要放的 


a1 = a2 & a3 & a4 ... & an 
an = a1 & a2 & a3 ... & an-1

a1 = a1 & a2 & a3 ... & an
an = a1 & a2 & a3 ... & an 

*/