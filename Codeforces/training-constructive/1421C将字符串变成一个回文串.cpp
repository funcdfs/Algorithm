// LINK: https://codeforces.com/contest/1421/problem/C
// NAME: 1421C. Palindromifier, Codeforces - Codeforces Round #676 (Div. 2)
// DATE: 2022.09.27 14:57:04, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string s = ""; 
   cin >> s; 
   int n = s.size(); 
   
   cout << 3 << '\n'; 
   
   cout << "R" << ' ' << n - 1 << '\n'; 
   cout << "L" << ' ' << n     << '\n'; 
   cout << "L" << ' ' << 2     << '\n'; 
   return 0;
}


/*

1421C将字符串变成一个回文串


可以将 s2 \to si 反转, 并反向添加到字符串前面
可以将 si \to s_{n - 1} 反转，并反向添加到字符串的最后面 


假设原字符串为 Tcd (T 为前半部分的字符，c，d 是字符串中的倒数两个字符)

Tcd -> Tcdc -> dcT'Tcdc -> cdcT'Tcdc

*/