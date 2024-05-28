// LINK: https://codeforces.com/contest/999/problem/C
// NAME: C. Alphabetic Removals, Codeforces - Codeforces Round #490 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.29-17:31:02, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0; cin >> n >> k; 
   string s = ""; 
   cin >> s; 
   
   vector<int> cnt(26, 0); 
   for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++; 
   }
   for (int i = 0; i < 26; i++) {
      if (k <= 0) break; 
      int d = min(k, cnt[i]); 
      cnt[i] -= d; 
      k -= d; 
   }
   
   string t = ""; 
   for (int i = n - 1; i >= 0; i--) {
      if (cnt[s[i] - 'a'] > 0) {
         t += s[i]; 
         cnt[s[i] - 'a']--; 
      }
   }
   reverse(t.begin(), t.end()); 
   
   cout << t << '\n'; 
   
   return 0;
}

/*

从左到右字典序删除k个字符返回剩余的字符串

*/