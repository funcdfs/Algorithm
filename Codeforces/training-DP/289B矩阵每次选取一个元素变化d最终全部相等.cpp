// LINK: https://codeforces.com/contest/289/problem/B
// NAME: B. Polo the Penguin and Matrix, Codeforces - Codeforces Round #177 (Div. 2)
// DATE: 2022-08-26 22:53:20, LIMIT: 256 MB, 2000 ms

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
    
    int n = 0, m = 0, d = 0; 
    cin >> n >> m >> d; 
    vector<int> a(n * m, 0); 
    for (int i = 0; i < n * m; i++) cin >> a[i]; 
    
    set<int> S; 
    for (auto & x : a) S.insert(x % d); 
    if (S.size() > 1) {
        cout << -1 << "\n"; 
        return 0; 
    }
    /* below code have solution: */
    
    sort(a.begin(), a.end()); 
    int sum = 0; 
    for (int i = 0; i < n * m; i++) {
        sum += abs(a[i] - a[(n * m) >> 1]); 
    } 
    // all count, then need to divide d 
    
    cout << sum / d << "\n"; 
    return 0;
}


/*

289B矩阵每次选取一个元素变化d最终全部相等


无解： 
    当所有的数字对于 d 的取模得到的结果不完全相等的时候，这个空隙就无法填满。cout -1


比较大的数字一定要变小，而比较小的数字一定要变大 

假设 a < b < c 每次变化 d 

如果都要变成 a: 
    (b - a + c - a) / d = (b + c - 2a) / d 步
如果都变成 b: 
    (b - a + c - b) / d = (c - a) / d 步
如果都要变成 c: 
    (c - a + c - b) / d = (2c - b - a) / d 步
    
所以一定是变到中间的一个数字比较好一些 

扩展到 n 个数字，就是到达 中位数的时候更好 

*/