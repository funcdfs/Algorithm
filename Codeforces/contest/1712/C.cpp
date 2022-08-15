// URL: https://codeforces.com/contest/1712/problem/C
// NAME: C. Sort Zero, Codeforces - Codeforces Round #813 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-13 23:46:06

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> a(n + 1); 
        map<int, int> R; 
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; 
            R[a[i]] = i; 
        }
        int s = n; 
        while (s > 1 and a[s] >= a[s - 1]) {
            s -= 1; 
        } 
        
        set<int> S; 
        for (int i = 1; i < s; i++) {
            S.insert(a[i]); 
            s = max(R[a[i]] + 1, s); 
        }
        cout << S.size() << '\n'; 
    }

    return 0;
}

/*

找到最后一段，非严格单调递增的同时里面的数字不再前面出现的

*/

/*
5
3
3 3 2
4
1 3 1 3
5
4 1 5 3 2
4
2 4 1 2
1
1

1
2
4
3
0

*/

/*
1
7
7 6 1 2 3 4 5

2
*/

/*
1
6
3 2 6 3 5 5

3
*/

/*

被卡的原因:



*/