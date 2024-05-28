// LINK: https://codeforces.com/contest/1759/problem/B
// NAME: 1759B. Lost Permutation, Codeforces - Codeforces Round  #834 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.04-22:31:16, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
   	auto solve = []() -> void {
   		int m = 0, s = 0; 
   		cin >> m >> s; 
   		int maxVal = 0; 
   		for (int i = 0; i < m; i++) {
   			int x = 0; 
   			cin >> x; 
   			maxVal = max(maxVal, x); 
   			s += x; 
   		}
   		/* now s is the append part and the origin part's sum value*/ 
   		
   		for (int i = maxVal; i <= 200; i++) {
   			int x = i * (i + 1) / 2; 
   			if (s < x) {
   				cout << "NO\n"; 
   				return; 
   			}
   			if (s == x) {
   				cout << "YES\n"; 
   				return; 
   			}
   		}
   	};
   	solve(); 
   }
   
   return 0;
}

auto main2() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int m = 0, s = 0;
      cin >> m >> s;
      vector<int> b(m, 0);
      for (int i = 0; i < m; i++) cin >> b[i];

      auto judge = [&]() -> bool {
         unordered_map<int, int> hs;
         for (auto& x : b) hs[x]++;
         for (auto& [_, v] : hs)
            if (v > 1) return false;

         int64_t sum = 0;
         for (int i = 1; i <= 200; i++) {
            if (sum == s) {
               int maxVal = 0;
               for (auto& [k, _] : hs) {
                  maxVal = max(maxVal, k);
               }
               for (int i = 1; i <= maxVal; i++) {
                  if (hs.contains(i) == false) {
                     return false;
                  }
               }
               /* judge if this array is a permuation */
               return true;
            } else if (sum > s) {
               return false;
            }
            if (hs.contains(i) == false) {
               sum += i;
               hs[i]++;
            }
         }
         
         return false;
      };

      if (judge()) {
         cout << "YES\n";
      } else {
         cout << "NO\n";
      }
   }

   return 0;
}

/*

1759B是否可以补全缺失的排列

*/