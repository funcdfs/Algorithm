// LINK: https://atcoder.jp/contests/agc029/tasks/agc029_a
// NAME: A - Irreversible operation, AtCoder - AtCoder Grand Contest 029
// DATE: 2022.09.19 16:49:18, LIMIT: 1024 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    string s = ""; 
    cin >> s; 
    int n = (int)s.size(); 
    
    vector<int> wPos(0, 0); 
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            wPos.push_back(i); 
        }
    }
    dbg(wPos); 
    
    int64_t ans = 0; 
    int lastW = 0; 
    for (int i = 0; i < (int)wPos.size(); i++) {
        ans += wPos[i] - lastW; 
        lastW++; 
    }
    cout << ans << '\n'; 
    return 0;
}


/*

agc029_a可以反转相邻异色的最大步骤数量

选择 i 是 B，i + 1 是 W 
反转这两个盘子，

找出可以进行操作的最大步数



第一次操作可以将所有的 BBBW 类似段落全部找出来，并且将操作数量加上 

BBWBBW

WBBBBW
WWBBBB


WBBWBB

WWBBBB


https://atcoder.jp/contests/agc029/submissions/34993726
*/