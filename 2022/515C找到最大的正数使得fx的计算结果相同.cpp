// LINK: https://codeforces.com/contest/515/problem/C
// NAME: 515C. Drazil and Factorial, Codeforces - Codeforces Round #292 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.07-22:26:19, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */

string ch[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   string s = string(n, ' ');
   cin >> s;
   
   string ans = ""; 
   for (int i = 0; i < n; i++) {
      ans += ch[s[i] - '0']; 
   }
   sort(ans.begin(), ans.end()); 
   reverse(ans.begin(), ans.end()); 
   
   cout << ans << '\n'; 
   
   return 0;
}

/*

515C找到最大的正数使得fx的计算结果相同

0, 1 -> empty

2 -> 2

3 -> 3

4 -> 322

5 -> 5

6 -> 53

7 -> 7

8 -> 7222

9 -> 7332

Then,
sort all digits in decreasing order as a new number,
then it will be the answer.


*/