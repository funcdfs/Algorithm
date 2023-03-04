/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-05 00:35:06
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int unsigned long long

bool isSub(string a, string b) {
   int idxA = 0;
   for (int i = 0; i < (int)b.size(); i++) {
      if (idxA == (int)a.size()) {
         break;
      }
      if (b[i] == a[idxA]) {
         idxA += 1;
      }
   }
   if (idxA == (int)a.size()) {
      return true;
   }
   return false;
}

int32_t main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string a, b;
   cin >> a >> b;
   if (a == b) return cout << -1, 0;
   int maxLen = max((int)a.size(), (int)b.size());
   cout << maxLen << '\n';
   return 0;
}