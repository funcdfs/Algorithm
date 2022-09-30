// LINK: https://codeforces.com/contest/538/problem/B
// NAME: B. Quasi Binary, Codeforces - Codeforces Round #300
// DATE: 2022.09.13 16:23:58, LIMIT: 256 MB, 2000 ms

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
    
    vector<int> a(0, 0); 
    while (n > 0) {
        a.push_back(n % 10); 
        n /= 10; 
    }
    reverse(a.begin(), a.end()); 
    int cnt = *max_element(a.begin(), a.end()); 
    
    vector<string> ans; 
    for (int i = 0; i < cnt; i++) {
        string s = string((int)a.size(), '0'); 
        for (int j = 0; j < (int)a.size(); j++) {
            if (a[j] != 0) {
                a[j]--; 
                s[j] = '1'; 
            }
        }
        ans.push_back(s); 
    }
    
    cout << cnt << '\n'; 
    for (auto& s : ans) {
        cout << stoi(s) << ' '; 
    }
    
    return 0;
}


/*

538B将n分为二进制数位的数字的和的最少的数量

把每一个数字想象为一个二维的俄罗斯方块图形 

然后对于输出每一行（横着的）

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220913164403.png)

*/