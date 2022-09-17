// URL: https://codeforces.com/problemset/problem/894/A
// NAME: A. QAQ, Codeforces - Codeforces Round #447 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-04 14:00:55

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int cntQ, cntA, ans; 	

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s = ""; 
    cin >> s; 

    for (auto& c : s) {
    	if (c == 'Q') {
    		cntQ++;  
    		ans += cntA;   // 2: 如果是 q，那么这个 q 和前面的 qa 的数量就是 ans 的一部分
    	} else if (c == 'A') {
    		cntA += cntQ;  // 1: 累加以这个 a 为中间节点的 qa 序列的数量 
    	}
    }
    
    cout << ans << endl; 

    return 0;
}


/*

存在多少QAQ

不必连续

*/