// URL: https://codeforces.com/contest/1339/problem/A
// NAME: A. Filling Diamonds, Codeforces - Codeforces Round #633 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-11 21:56:52

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

int fullyCoveredMethodCnt(int n) {
    // f[n] = f[n - 1] + 1 (在一个六边形的菱形的左右各添加两个，和剩下的部分，剩下的部分就是 f[n - 1])
    return n; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0; 
        cin >> n; 
        cout << fullyCoveredMethodCnt(n) << endl; 
    }

    return 0;
}


/*

1339A使用菱形填满三角形腰带的方案数量 

每一个菱形横着摆放的方案数是 2 种 
竖着摆放的方案是 1 种

具体看图
https://www.luogu.com.cn/blog/mantou/solution-cf1339a
https://www.luogu.com.cn/problem/CF1339A
*/