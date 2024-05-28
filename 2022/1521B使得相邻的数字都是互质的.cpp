// LINK: https://codeforces.com/contest/1521/problem/B
// NAME: B. Nastia and a Good Array, Codeforces - Codeforces Round #720 (Div. 2)
// DATE: 2022-09-10 10:22:43, LIMIT: 256 MB, 2000 ms

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
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        int minVal = *min_element(a.begin(), a.end()); 
        int pos = find(a.begin(), a.end(), minVal) - a.begin(); 
        
        dbg(minVal, pos); 
        
        int first = 1e9 + 7; 
        int second = 1e9 + 9; 
        vector<vector<int>> path; 
        for (int i = 0; i < pos; i++) {
            path.push_back({i + 1, pos + 1, first, minVal}); 
            swap(first, second); 
        } 
        
        for (int i = pos + 1; i < n; i++) {
            path.push_back({pos + 1, i + 1, minVal, second}); 
            swap(first, second); 
        } 
        
        cout << path.size() << '\n'; 
        if (path.size() == 0) continue; 
        for (auto& x : path) {
            for (int i = 0; i < (int)x.size(); i++) {
                cout << x[i] << " \n"[i == x.size() - 1]; 
            }
        }
        
        dbg(a); 
    }
    
    return 0;
}


/*

1521B使得相邻的数字都是互质的

扫描一遍序列，找到整个序列的最小值并记录这个数字的位置 

然后将其他的 n - 1 个位置修改 
最小值的位置还是放置最小值，修改的那一个地方放置一个 1e9 - 2*1e9 之间的质数 

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220910150408.png)

*/