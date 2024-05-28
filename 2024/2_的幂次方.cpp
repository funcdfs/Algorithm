/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 18:55:34
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

string dfs(int n) {
    string ans;
    for (int i = 14; i >= 0; i--) { // 从高位到低位转换
        if ((n >> i) & 1) {
            if (ans.size()) ans += '+';
            if (i == 0) ans += "2(0)"; // 加上 1
            else if (i == 1) ans += "2"; // 加上 2 
            else ans += "2(" + dfs(i) + ")"; // 大于 2 的递归执行
        }
    }
    return ans;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0;
    while (cin >> n) {
        cout << dfs(n) << endl;
    }
    
    return 0;
}
/*

*/