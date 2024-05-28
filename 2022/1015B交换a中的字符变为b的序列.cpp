// LINK: https://codeforces.com/contest/1015/problem/B
// NAME: 1015B. Obtaining the String, Codeforces - Codeforces Round #501 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.07-11:18:46, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   string s, t; 
   cin >> s >> t;
   dbg(n, s, t); 
   
   vector<int> ans(0, 0);
   for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) continue; 
      int pos = -1; 
      for (int j = i + 1; j < n; j++) {
         if (s[j] == t[i]) {
            pos = j; 
            break; 
         }
      }
      if (pos == -1) {
         return cout << -1, 0; 
      }
      for (int j = pos - 1; j >= i; j--) {
         swap(s[j], s[j + 1]); 
         ans.push_back(j); 
      }
   }
   dbg(s, t); 
   assert(s == t); 
   cout << ans.size() << '\n'; 
   for (auto& x : ans) cout << x + 1 << ' '; 
   
   return 0;
}

/*

1015B交换a中的字符变为b的序列

iterate all i from 1 to n, 
go further,
otherwise let's find any position j > i 
such that sj == ti and move the character from the position j to the position i
if there is no such position in s, the answer is "-1"


*/