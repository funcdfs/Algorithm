// LINK: https://codeforces.com/contest/268/problem/C
// NAME: 268C. Beautiful Sets of Points, Codeforces - Codeforces Round #164 (Div. 2)
// DATE: 2022.09.22 22:40:07, LIMIT: 256 MB, 1000 ms

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
    // ![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220922234320.png)
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    
    int x = min(n, m); 
    cout << x + 1 << '\n'; 
    for (int i = 0; i <= x; i++) {
        cout << i << ' ' << x - i << '\n'; 
    }
    // y + x == dist 的直线
    
    return 0;
}

int main_fw() {
    
    // 题目中的条件是: x + y > 0 所以不可以按照 0 0 为起点
    // ![00为起点的推理](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220922233737.png)
    
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    
    int minVal = min(n, m); 
    vector<pair<int, int>> ans; 
    vector<int> points{0, 0, 1, 2, 2, 1}; 
    bool two = false; 
    bool f1 = true, f2 = true; 
    while (true) {
        if (f2 == false && f1 == false) {
            break; 
        }
        if (two == true) {
            ans.push_back({points[2], points[3]}); 
            ans.push_back({points[4], points[5]}); 
            points[2] += 3, points[3] += 3; 
            points[4] += 3, points[5] += 3; 
            two = false;
            if (points[2] > n || points[3] > m || points[4] > n || points[5] > m) {
                f2 = false; 
            }
        } else {
            ans.push_back({points[0], points[1]}); 
            points[0] += 3, points[1] += 3; 
            two = true; 
            if (points[0] > minVal) {
                f1 = false; 
            }
        }
    }
    
    cout << ans.size() << '\n'; 
    for (auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n'; 
    }
    
    return 0;
}


/*

268C构建漂亮的点集合

集合中的所有的点都是整数，同时对于集合中的任意两个点 他们之间的距离不是整数

*/