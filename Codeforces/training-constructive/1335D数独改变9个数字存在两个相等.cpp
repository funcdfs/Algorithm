// LINK: https://codeforces.com/contest/1335/problem/D
// NAME: D. Anti-Sudoku, Codeforces - Codeforces Round #634 (Div. 3)
// DATE: 2022-09-08 22:19:49, LIMIT: 256 MB, 2000 ms

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

    int tt = 0;
    cin >> tt; 
    
    while (tt--) {
        vector<string> s(9, "");
        for (int i = 0; i < 9; i++) {
            cin >> s[i];
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[i].size(); j++) {
                if (s[i][j] == '1') {
                    s[i][j] = '2';
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << endl;
        }
    }

    return 0;
}

/*

1335D数独改变9个数字存在两个相等

输入的数独合法
改变最多 9 个数字使得，每一行，每一列，每一个小方格中至少有两个数字相等

输出任意一种合格的解法

*/