// LINK: https://codeforces.com/contest/1350/problem/B
// NAME: 1350B. Orac and Models, Codeforces - Codeforces Round #641 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.02-21:54:18, 3000 ms

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
      vector<int> a(n + 1, 0);
      for (int i = 0; i < n; i++) cin >> a[i + 1];
      
      vector<int> f(n + 1, 0); 
      fill(f.begin(), f.end(), 1); 
      
      for(int i = 1; i <= n; i++) {
         for (int j = 2 * i; j <= n; j += i) {
            if (a[i] < a[j] && f[i] >= f[j]) {
               f[j] = f[i] + 1; 
            }
         }
      }
      cout << *max_element(f.begin() + 1, f.end()) << '\n'; 
   }

   return 0;
}


/*

1350B最长递增子序列后一个数字是前一个数字的倍数

*/