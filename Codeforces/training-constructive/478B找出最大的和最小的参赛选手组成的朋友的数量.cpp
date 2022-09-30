// LINK: https://codeforces.com/contest/478/problem/B
// NAME: B. Random Teams, Codeforces - Codeforces Round #273 (Div. 2)
// DATE: 2022-09-07 15:26:40, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    
    if (n < m) {
        cout << 0 << ' ' << 0 << endl; 
        return 0; 
    } 
    
    function<int(int64_t)> cal = [](int64_t x) {
        return x * (x - 1) / 2; 
    };
    int64_t k = n % m; 
    int64_t minVal = k * cal(n / m + 1) + (m - k) * cal(n / m);
    int64_t maxVal = cal(n - m + 1); 
    
    cout << minVal << ' ' << maxVal << endl; 
    
    return 0;
}


/*

478B找出最大的和最小的参赛选手组成的朋友的数量

n 个参赛者，会被分成 m 个小组，每一个小组内都会成为朋友

最少情况就是平均分配， 每一个组的成员尽量均衡 
最多的情况就是一个组最多，然后剩下的组的成员依次递减 


如果一组中存在 n 个人， 那么这一组中的朋友的对数就是 n * (n - 1) / 2 

TODO: minval part 
*/