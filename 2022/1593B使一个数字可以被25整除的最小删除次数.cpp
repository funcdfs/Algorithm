// URL: https://codeforces.com/contest/1593/problem/B
// NAME: B. Make it Divisible by 25, Codeforces - Codeforces Round #748 (Div. 3)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-12 16:45:23

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL           
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const string subSeqs[] = {"00", "25", "50", "75"}; 
const int INF = 100; 

int solve(string& s, string& t) {
    // 寻找末尾数字变为 e 的时候的，n 需要删除的最小的次数 
    int sptr = s.length() - 1; 
    int ans = 0; 
    while (sptr >= 0 && s[sptr] != t[1]) {
        sptr--; 
        ans++; 
    } 
    if (sptr < 0) return INF; 
    sptr--; 
    
    while (sptr >= 0 && s[sptr] != t[0]) {
        sptr--; 
        ans++; 
    }
    if (sptr < 0) return INF; 
    return ans; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        string n; 
        cin >> n; 
        
        int ans = INF; 
        for (auto e : subSeqs) {
            ans = min(ans, solve(n, e)); 
        } 
        cout << ans << endl; 
    }

    return 0;
}


/*

1593B使一个数字可以被25整除的最小删除次数

一个数字可以被25整除只有四种情况 

该数字的末尾两位是 00 
该数字的末尾两位是 50 
该数字的末尾两位是 75 
该数字的末尾两位是 25 

*/