// URL: https://codeforces.com/contest/1475/problem/B
// NAME: B. New Year's Number, Codeforces - Codeforces Round #697 (Div. 3)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-11 21:22:00

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

bool canSplitTwoNumber(int n, int a, int b) { 
    if (n < min(a, b)) return false; 
    if (a > b) return canSplitTwoNumber(n, b, a); 
    int s = n / a; // 商
    int r = n % a; // 余数
    
    // 要把这个余数消除掉，就只能把 r 个 2020 改成 2021 了 
    if (r <= s) {
        return true; 
    } else {
        return false; 
    } 
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        if (canSplitTwoNumber(n, 2020, 2021)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*

1475B判断能否拆分为2020和2021

n = 2020 * a + 2021 * b 

a b 都是正整数，并且 a 和 b 不同时为 0 
*/