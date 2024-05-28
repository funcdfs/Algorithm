// LINK: https://codeforces.com/contest/1363/problem/B
// NAME: 1363B. Subsequence Hate, Codeforces - Codeforces Round #646 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.19-18:21:04, 1000 ms

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

vector<string> getShapes(string& s) {
   int n = (int)s.size(); 
   vector<string> ans(0, ""); 
   ans.reserve(2 * n); 
   for (int i = 0; i < n; i++) {
      ans.push_back(string(i, '1') + string(n - i, '0')); 
      ans.push_back(string(i, '0') + string(n - i, '1')); 
   }
   return ans; 
}

int diff(string& a, string& b) {
   int ans = 0; 
   for (int i = 0; i < (int)a.size(); i++) {
      if (a[i] != b[i]) {
         ans++; 
      }
   }
   return ans; 
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(0);
   int tt = 0; 
   while (tt--) {
      string s = ""; 
      cin >> s; 
      vector<string> shapes = getShapes(s); 
      int ans = numeric_limits<int>::max(); 
      for (int i = 0; i < (int)shapes.size(); i++) {
         ans = min(ans, diff(shapes[i], s)); 
      }
      cout << ans << '\n'; 
   }
   
   return 0;
}


/*

1363B使得01字符串只可以存在一个分界线的最少反转次数

*/