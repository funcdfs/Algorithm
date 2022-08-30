// LINK: https://codeforces.com/contest/266/problem/B
// NAME: B. Queue at the School, Codeforces - Codeforces Round #163 (Div. 2)
// DATE: 2022-08-29 21:35:04, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0, t = 0; 
    cin >> n >> t; 

    string s = ""; 
    cin >> s; 

    // t == 50, n == 50 

    for (int time = 1; time <= t; time++) {
        for (int i = 0; i + 1 < n; ) {
            debug(time, i, s);
            if (s[i] == 'B' && s[i + 1] == 'G') {
                swap(s[i], s[i + 1]); 
                i += 2; 
            } else {
                i += 1; 
            }
            debug("after"); 
            debug(time, i, s); 
            cerr << "\n"; 
        }
    }

    cout << s << '\n'; 
    
    return 0;
}


/*

266B食堂中的队列

小女孩们每一秒都可以向前走一步 

食堂从前往后进行上菜

如果 x 时间的时候，BG 出现了，那么时间是 x + 1 的时候，就会变成 GB

给定初始的状态，求时间 t 之后队列的具体状态

*/