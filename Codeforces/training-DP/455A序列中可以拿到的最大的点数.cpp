// LINK: https://codeforces.com/contest/455/problem/A
// NAME: 455A. Boredom, Codeforces - Codeforces Round #260 (Div. 1)
// CODE: https://github.com/fengwei2002, 2022.10.06-20:24:22, 1000 ms
   
   #include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   map<int64_t, int64_t> freq; 
   for (auto& x : a) freq[x]++; 
   int maxValue = *max_element(a.begin(), a.end()); 
   vector<int64_t> f(maxValue + 1, 0); 
   f[1] = freq[1]; 
   for (int i = 2; i <= maxValue; i++) {
      f[i] = max(f[i - 1], f[i - 2] + freq[i] * i); 
   }
   cout << f[maxValue] << '\n'; 
   
   return 0;
}

int main_fw() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   
   priority_queue<pair<int, int64_t>, vector<pair<int, int64_t>>, less<>> hp; 
   unordered_map<int, int> freq; 
   for (auto& x : a) freq[x]++; 
   
   unordered_map<int, int64_t> w; 
   for (auto& x : a) w[x] = freq[x] * x; 
   
   for (auto& [k, v] : w) {
      dbg(v, k); 
      hp.push({v, k}); 
   }
   int64_t ans = 0; 
   auto t = hp.top(); 
   dbg(t); 
   hp.pop(); 
   ans += t.first; 
   set<int> s; 
   s.insert(t.second); 
   s.insert(t.second + 1); 
   s.insert(t.second - 1); 
   while (!hp.empty()) {
      while (!hp.empty() && s.contains(hp.top().second)) {
         hp.pop(); 
      }
      if (hp.empty()) break; 
      dbg(hp.top());
      t = hp.top(); 
      hp.pop(); 
      ans += t.first; 
      s.insert(t.second); 
      s.insert(t.second + 1); 
      s.insert(t.second - 1); 
   }
   
   cout << ans << '\n'; 

   return 0;
}

/*

455A序列中可以拿到的最大的点数


5
3 3 4 5 4
11 not 8

final version: 
https://codeforces.com/contest/455/submission/174859004
*/