// LINK: https://codeforces.com/contest/1759/problem/A
// NAME: 1759A. Yes-Yes?, Codeforces - Codeforces Round  #834 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.04-22:04:11, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve(string& s) -> bool {
	string t = "Yes";
	int n = (int)s.size(); 
	for (int k = 0; k < 3; k++) {
		bool ok = true; 
		for (int i = 0; i < n; i++) {
			if (s[i] != t[(i + k) % 3]) {
				ok = false; 
				break; 
			}
		}
		if (ok == true) return true; 
	}
	// O(3n)
	return false;
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
   	string s = ""; 
   	cin >> s; 
   	if (solve(s)) {
   		cout << "YES\n"; 
   	} else {
   		cout << "NO\n"; 
   	}
   }
   
   return 0;
}

/*
1759A判断是否是一个 Yes 的子串
*/