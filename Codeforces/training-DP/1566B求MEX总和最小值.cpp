// URL: https://codeforces.com/contest/1566/problem/B
// NAME: B. MIN-MEX Cut, Codeforces - Codeforces Global Round 16
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-10 11:16:07

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
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
    	string s = ""; 
    	cin >> s; 
    	
    	int num = (s[0] == '0'); 
    	for (int i = 1; i < s.size(); i++) {
    		if (s[i] != s[i-1]) {
    			num += (s[i] == '0'); 
    		}
    	} 
    	
    	cout << min(num, 2) << endl; 
    }

    return 0;
}


/*

定义一个二进制串的 mex 值，是其中二进制下最小的没出现过的，都出现过的就是 2 

给定一个二进制串，可以分成若干段不为空的子字符串，求每段 mex 值的总和的最小值 

一个全是 0 的串 mex 是 1 
一个全是 1 的串 mex 是 0 
如果这个子串有 0 并且有 1 mex 就是 2 

其他的都是 2 

*/