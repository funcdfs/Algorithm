/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-04 23:11:53
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
   cout << s;
   reverse(s.begin(), s.end());
   cout << s;
   return 0;
}