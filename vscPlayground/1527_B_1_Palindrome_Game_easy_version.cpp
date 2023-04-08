/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-08 23:25:29
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const string aWin = "ALICE\n";
const string bWin = "BOB\n";
const string bothWin = "DRAW\n";

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   // s, length is n
   // choose any i s[i] == '0' and change s[i] to '1' pay 1 dollar
   // reverse the whole string pay 0 dollar, if the string is not a palindrome
   //    the last operation was not reverse 
   //    if alice reverses the string, then bob can't reverse in the next move

   // the game end when every character of string becomes '1'
   // the player who spends minimum dollars till this point wins the game and it is a draw if both spend equal dollars
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      string s = "";
      cin >> s;
      int zeroCnt = count(s.begin(), s.end(), '0');
      if (zeroCnt % 2 == 0) {
         cout << bWin;
      } else if (zeroCnt % 2) {
         if (zeroCnt == 1) {
            cout << bWin;
         } else {
            cout << aWin;
         }
      }
   }
   
   return 0;
}

/*

![2023-03-08-23-57-20](https://raw.githubusercontent.com/psychonaut1f/a/main/img/2023-03-08-23-57-20.png)

*/