/**
 * name:  小玉买文具
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1421
 * time: 2024/5/17 11:37:46 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */



auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int a , b;
    cin >> a >> b;

    int x = a * 10 + b;
    cout << format("{0}\n", x / 19);
    
    return 0;
}
/*

*/