// LINK: https://codeforces.com/contest/1368/problem/C
// NAME: 1368C. Even Picture, Codeforces - Codeforces Global Round 8
// DATE: 2022.09.20 09:11:49, LIMIT: 512 MB, 2000 ms

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
    
    int n = 0; 
    cin >> n; 
    cout << 3 * n + 4 << '\n'; 
    cout << 0 << ' ' << 0 << '\n'; 
    for (int i = 0; i <= n; i++) {
        cout << i << ' ' << i + 1 << '\n';     // 上边
        cout << i + 1 << ' ' << i << '\n';     // 右边 
        cout << i + 1 << ' ' << i + 1 << '\n'; // 右上角
    }
    // ![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220920094201.png)
    // https://codeforces.com/contest/1368/submission/84179825
    return 0;
}


/*

1368C画一个灰色格子组成的漂亮的画

画画，四方向联通的话，就是联通的
- 所有的灰色的小方格都是互相联通的
- 每一个灰色的格子都拥有偶数个相邻的格子
- 只存在 n 个单元格的灰色格子拥有所有方向的邻居





![1](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220920093648.png)

或者这种补充空隙的写法：奇数补充空隙，偶数就直接画成一个矩形
![2](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220920093621.png)


但是 1 写起来更加方便一些
所以可以使用 1 

*/