// LINK: https://codeforces.com/contest/550/problem/A
// NAME: 550A. Two Substrings, Codeforces - Codeforces Round #306 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.06-21:34:58, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   string s = "";
   cin >> s;
   int n = (int)s.size(); 
   vector<int> v1, v2; 
   for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
         v1.push_back(i); 
      } else if (s[i] == 'B' && s[i + 1] == 'A') {
         v2.push_back(i); 
      }
   }
   if (v1.empty() || v2.empty()) {
      cout << "NO\n"; 
      return 0; 
   }
   if (abs(v1[0] - v2.rbegin()[0]) <= 1 && abs(v2[0] - v1.rbegin()[0]) <= 1) {
      cout << "NO\n"; 
      return 0; 
   }
   cout << "YES\n";

   return 0;
}

/*

550A判断字符串中是否存在不重叠的一个AB和一个BA


ABAB NO

ABAXXAB YES
![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221006221718.png)

*/