// URL: https://codeforces.com/problemset/problem/996/A
// NAME: A. Hit the Lottery, Codeforces - Codeforces Round #492 (Div. 2) [Thanks, udbg!]
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-04 12:06:51

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> bills{1, 5, 10, 20, 100}; 
	
	int n = 0; 
	cin >> n; 
	
	long ans = 0; 
	int index = bills.size() - 1; 
	while (n >= 0) {
		// dbg(n, ans, index, bills[index]); 
		if (n >= bills[index]) {
			n -= bills[index]; 
			ans++; 
		} else {
			index--; 
		}
		if (index < 0) {
			break; 
		}
	}
	
	cout << ans << endl; 
	
    return 0;
}


/*

f[i] 代表价值为 i 的时候，需要的账单的最少数量

最终答案为 f[n] 

*/