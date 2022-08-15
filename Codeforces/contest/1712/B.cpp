// URL: https://codeforces.com/contest/1712/problem/B
// NAME: B. Woeful Permutation, Codeforces - Codeforces Round #813 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-13 23:22:05

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

int gcd(int a, int b) {
    int c = b;
    while (a % b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x = 0; 
    string a = "aa"[x == 1]
    cout << a << endl; 
    
    return 0;
}

/*

1, 2, 3, 4, 5, 6, 7

n = 7

给定一个排列，排列的每一项都和上面的求最小公倍数




*/