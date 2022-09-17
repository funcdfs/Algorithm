// URL: https://codeforces.com/problemset/problem/1462/B
// NAME: B. Last Year's Substring, Codeforces - Codeforces Round #690 (Div. 3)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-04 15:15:29

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

bool solve(string& s) {
	int n = s.size(); 
	for (int i = 0; i <= 4; i++) {
		if (s.substr(0, i) + s.substr(n - 4 + i, 4 - i) == "2020") {
			return true; 
		}
	} 
	return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
    	int length = 0; 
    	cin >> length; 
    	string s = ""; 
    	cin >> s; 
    	if (solve(s)) {
    		cout << "YES" << endl; 
    	} else {
    		cout << "NO" << endl; 
    	}
    }

    return 0;
}


/*

是否可以得到完整的2020

*/