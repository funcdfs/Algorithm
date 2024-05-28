// LINK: https://codeforces.com/contest/706/problem/B
// NAME: B. Interesting drink, Codeforces - Codeforces Round #367 (Div. 2)
// DATE: 2022-08-22 20:50:08, LIMIT: 256 MB, 2000 ms

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
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    int m = 0; 
    cin >> m; 
    vector<int> b(m, 0); 
    for (int i = 0; i < m; i++) cin >> b[i]; 
    
    sort(a.begin(), a.end()); 
    // a.erase(unique(a.begin(), a.end()), a.end()); 
    
    function<int(int)> search = [&](int x) {
        if (x < a[0]) return 0; 
        if (x > a.rbegin()[0]) return int(a.size()); 
        
        int l = 0, r = a.size() - 1; 
        while (l < r) {
            int mid = (l + r + 1) >> 1; 
            if (a[mid] <= x) {
                l = mid; 
            } else {
                r = mid - 1; 
            }
        } 
        
        return l + 1; 
    };
    
    for (int i = 0; i < m; i++) {
        int x = b[i]; 
        cout << search(x) << "\n"; 
    }
    
    return 0;
}


/*

706B小于某个数字的数量

求的是具体的数量，所以不应该去重，排序即可

二分
*/