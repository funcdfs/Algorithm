// LINK: https://codeforces.com/contest/1370/problem/C
// NAME: 1370C. Number Game, Codeforces - Codeforces Round #651 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.09-22:55:48, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */

void player_1() { cout << "Ashishgup" << '\n'; }

void player_2() { cout << "FastestFinger" << '\n'; }

bool check_prime(int n) {
   n = min(50000, n); 
   for (int i = 2; i < n; i++)
      if (n % i == 0) return false;
   return true;
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      bool lose = (n == 1); 
      if (n > 2 && (n % 2) == 0) {
         if (n & (n - 1) == 0) {
            lose = true; 
         } else if (n % 4 != 0 && check_prime(n / 2)) {
            lose = true; 
         }
      }
      if (lose == true) {
         player_2();  
      } else {
         player_1(); 
      }
   }

   return 0;
}

/*

1370C除一个数字或者减去一找最终的赢家

如果 n

*/