// LINK: https://codeforces.com/contest/1081/problem/C
// NAME: C. Colorful Bricks, Codeforces - Avito Cool Challenge 2018
// DATE: 2022-08-23 22:27:58, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

const int moder = 998244353;
const int N = 2010;


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    // number of bricks, number of colors, diff left count
        
    
    
    return 0;
}

/*

1081C颜色不同的砖块组合总数

3 3 0
所有的砖块都是一种颜色， 一共三种不同的放置方式

3 2 1
只有一个砖块是和左边的砖块颜色不同的， 可以有 4 种放置方式

解法:

首先不考虑颜色，
    也就是在 n - 1 个空隙中选择 k 个不同的空隙 C_{n - 1}^{k}
再考虑颜色，共 k 个整体，每一个整体不能使用上一个整体的颜色
    染色不同整体的方式: m * (m-1)^{k}, (k 个隔板，k + 1 个区间)

两种状态互不影响，所以计算相乘的结果作为答案

TODO: 数论，组合计数，阶乘

*/