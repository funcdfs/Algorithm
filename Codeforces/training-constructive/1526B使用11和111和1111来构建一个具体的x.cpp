// LINK: https://codeforces.com/contest/1526/problem/B
// NAME: 1526B. I Hate 1111, Codeforces - Codeforces Round #723 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.02-10:34:46, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int x = 0;
      cin >> x;
      
      int r = x % 11; 
      int s = x / 11; 
      if (s >= r * 10) {
         cout << "YES\n"; 
      } else {
         cout << "NO\n"; 
      }
   }

   return 0;
}

/*

1526B使用11和111和1111来构建一个具体的x


1111 = 11*101
除了 11 和 111 之外的所有的数字都是没用的

1111 = 11*100 + 11
11111 = 111*100 + 11

所以可以使用 11 和 111 构造 1111 和以后的数字 
所以问题就变为了，是否可以使用 11 和 111 来构造具体的 x 

x = A*11 + B*111
x = A*11 + B*10*11 + B
x = (A + B*10)*11 + B
x 整除 11 之后剩下的那一个数字，余数小于 11 


*/