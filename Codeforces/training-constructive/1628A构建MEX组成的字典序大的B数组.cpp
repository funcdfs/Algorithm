// LINK: https://codeforces.com/contest/1628/problem/A
// NAME: 1628A. Meximum Array, Codeforces - Codeforces Round #767 (Div. 1)
// DATE: 2022.09.18 21:56:27, LIMIT: 256 MB, 2000 ms

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
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        unordered_map<int, int> hs; 
        for (auto& x : a) hs[x]++; 
        
        vector<int> b(0, 0); 
        for (int i = 0, j = 0; i < n; ) {
            int MEX = 0; 
            while (hs[MEX] > 0) MEX++; 
            
            int x = 0; 
            set<int> s; 
            while (true) {
                hs[a[j]]--; 
                s.insert(a[j]); 
                j++; 
                
                while (s.count(x)) x++; 
                if (x == MEX) break;  
            }
            b.push_back(MEX); 
            
            i = j; 
        }
        dbg(b); 
        cout << b.size() << '\n';
        for (int i = 0; i < (int)b.size(); i++) {
            cout << b[i] << " \n"[i == (int)b.size() - 1]; 
        }
    }
    
    return 0;
}


/*

1628A构建MEX组成的字典序大的B数组


给定一个 a 数组，里面都是正数，想要创建一个 b 数组

当 a 不空的时候：
- 选定一个整数 k （a 中的一个下标）
- 将前 k 个数字的 MEX value 加到 b 的后面，然后将这些数字从 a 中删除，将 a 的剩余部分向前移动

求使得数组 b 字典序最大的 



the MEX 是一个 set 中最小没有出现的正数  MEX{1, 2, 3} = 0, MEX{0, 1, 2, 4, 5} = 3; 

idea from: heltion
https://codeforces.com/contest/1628/submission/143635514
*/