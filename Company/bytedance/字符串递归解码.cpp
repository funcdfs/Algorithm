#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

string dfs(string& s, int& u) {
   string ans = ""; 
   while (u < (int)s.size() && s[u] != ']') {
      if (isalpha(s[u])) {
         ans += s[u]; 
         u++; 
      } else if (isdigit(s[u])) {
         int k = u; 
         while (k < (int)s.size() && isdigit(s[k])) {
            k++; 
         }
         int x = stoi(s.substr(u, k - u)); 
         u = k + 1; 
         
         string y = dfs(s, u); 
         u++; // 过滤掉右括号 
         while (x--) {
            ans += y; 
         }
      }
   }
   return ans; 
}

string decodeString(string s) {
   int u = 0; 
   return dfs(s, u); 
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string s = ""; 
   cin >> s; 
   
   // 3[a]2[bc]
   // aaabcbc
   
   // 3[a2[c]]
   // accaccacc

   cout << decodeString(s) << '\n'; 
   
   return 0;
}

/*



*/