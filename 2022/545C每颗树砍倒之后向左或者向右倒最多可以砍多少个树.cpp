// LINK: https://codeforces.com/contest/545/problem/C
// NAME: 545C. Woodcutters, Codeforces - Codeforces Round #303 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.08-20:02:04, 1000 ms

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
   if (n == 1) {
      cout << 1 << '\n'; 
      return 0; 
   }
   vector<int> x(n, 0), h(n, 0); 
   for (int i = 0; i < n; i++) {
      cin >> x[i] >> h[i]; 
   }
   
   int ans = 2; 
   for (int i = 1; i < n - 1; i++) {
      if (x[i] - h[i] > x[i - 1]) {
         ans++; 
      } else if (x[i] + h[i] < x[i + 1]) {
         ans++; 
         x[i] += h[i]; 
      }
   }
   cout << ans << '\n'; 

   return 0;
}


/*

545C每颗树砍倒之后向左或者向右倒最多可以砍多少个树


题目问最多可以砍倒几个树，并没有要求砍倒的树的长度最长
所以可以贪心的，如果一个树可以向左倒，就向左倒 
   否则，试着向右倒，这样就可以在从前往后遍历的时候，使得前面剩下的空隙尽可能的少
*/