// LINK: https://codeforces.com/contest/1747/problem/B
// NAME: 1747B. BAN BAN, Codeforces - Codeforces Round #832 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.04-23:05:29, 1000 ms

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
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0; 
      cin >> n; 
      if (n == 1) {
         cout << 1 << '\n'; 
         cout << 1 << ' ' << 2 << '\n'; 
         continue; 
      }
      
      vector<int> A(0, 0), N(0, 0); 
      int aIdx = 2, nIdx = 3; 
      for (int i = 0; i < n; i++) {
         A.push_back(aIdx); 
         aIdx += 3; 
         N.push_back(nIdx); 
         nIdx += 3; 
      }
      dbg(A, N); 
      int m = (int)A.size() / 2;
      if ((int)A.size() % 2) {
         m++; 
      } 
      cout << m << '\n' ;
      reverse(N.begin(), N.end()); 
      for (int i = 0; i < m; i++) {
         cout << A[i] << ' ' << N[i] << '\n'; 
      }
   }
   
   return 0;
}


/*

1747B打乱字符串的顺序使得不存在一个BAN的序列

*/