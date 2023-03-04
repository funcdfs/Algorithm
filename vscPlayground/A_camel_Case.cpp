/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 22:16
**/

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

   for (int i = 0; i < (int)s.size(); i++) {
      if (isupper(s[i])) {
         cout << i + 1 << '\n';
         return 0;
      }
   }

   return 0;
}


/*



*/
