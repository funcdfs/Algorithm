// URL: https://codeforces.com/contest/910/problem/A
// NAME: A. The Way to Home, Codeforces - Testing Round #14 (Unrated)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-10 13:18:26

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int canReachEnd(string& s, int d) {
	int ed = 0; 
	int ans = 0; 
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') { 
			bool canReach = false; 
			for (int j = i + 1; j < min(int(s.size()), i + 1 + d); j++) {
				if (s[j] == '1') {
					ed = j;  
					canReach = true; 
				}
			}
			if (canReach == true) {
				i = ed - 1;  
				ans++; 
			} else {
				if (s[i] == '1' && i == s.size() - 1) {
					return ans; 
				}
				return -1; 
			}
		}
	} 

	return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0, d = 0; 
    cin >> n >> d; 
    
    string s = ""; 
    cin >> s; 
    
    cout << canReachEnd(s, d) << endl; 
    
    return 0;
}


/*

910A青蛙回家

每次最多可以跳 d 步，只可以跳到 1 的位置，求最后能否到达最后一个位置 

*/