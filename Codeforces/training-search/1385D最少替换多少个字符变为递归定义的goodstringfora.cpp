// LINK: https://codeforces.com/contest/1385/problem/D
// NAME: 1385D. a-Good String, Codeforces - Codeforces Round #656 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.13-12:51:15, 2000 ms

#include <iostream>
#include <algorithm>
using namespace std; 

int solve(const string& s, char c) {
   if ((int)s.size() == 1) {
      if (s[0] == c) return 0; 
      return 1; 
   } 
   int mid = (int)s.size() / 2; 
   int cntl = solve(string(s.begin(), s.begin() + mid), c + 1); 
   // front part become c + 1 good string 
   cntl += (int)s.size() / 2 - count(s.begin() + mid, s.end(), c); 
   // the number of char in the second half not equal to the c 
   
   // right part is same: 
   int cntr = solve(string(s.begin() + mid, s.end()), c + 1); 
   cntr += (int)s.size() / 2 - count(s.begin(), s.begin() + mid, c); 
   
   return min(cntl, cntr); 
}

int main() {
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0; 
      cin >> n; 
      string s = string(n, ' '); 
      cin >> s; 
      cout << solve(s, 'a') << '\n'; 
   }
}


/*
1385D最少替换多少个字符变为递归定义的goodstringfora


一个 string 定义为 c 的 good string 
如果字符串的长度是 1 的话，等于 c 
否则
   要么前半部分是字符 c 然后后半部分是 C+1 的 good string 
   要么后半部分是字符 c 然后前半部分是 C+1 的 good string 

最终的问题是变为 good string for a

https://codeforces.com/contest/1385/submission/175889430
*/