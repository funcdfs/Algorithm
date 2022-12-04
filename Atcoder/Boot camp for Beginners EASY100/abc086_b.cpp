// LINK: https://atcoder.jp/contests/abc086/tasks/abc086_b
// NAME: B - 1 21, AtCoder - AtCoder Beginner Contest 086
// CODE: https://github.com/fengwei2002, 2022.12.03-22:26:50, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string a = "", b = ""; 
   cin >> a >> b; 
   a.append(b);
   
   int num = stoi(a); 
   double x = sqrt(num); 
   if ((int)x * (int)x == num) {
      return cout << "Yes", 0; 
   } else {
      return cout << "No", 0; 
   }
   
   return 0;
}

/*



*/