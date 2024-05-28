// LINK: https://codeforces.com/contest/1497/problem/C2
// NAME: C2. k-LCM (hard version), Codeforces - Codeforces Round #708 (Div. 2)
// DATE: 2022.09.15 23:35:25, LIMIT: 256 MB, 1000 ms

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
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < k - 3; ++i) cout << 1 << " ";
        n -= k - 3;
        if(n > 0) {
            if(n % 2) {
                cout << 1 << " " << n / 2 << " " << n / 2 << endl;
            } else {
                if(n % 4 == 0) {
                    cout << n / 4 << " " << n / 4 << " " << n / 2 << endl;
                } else {
                    cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
                }
            }
        }
    }
}

int main_test() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0, k = 0; 
        cin >> n >> k; 
        
        int t = k; 
        dbg("init: ", (n % t)); 
        while ((n % t) != 0) {
            dbg(n, t); 
            n--; // 总量减去 1
            t--; // 坑的位置少了一个 （放了一个 1 ）
        }
        vector<int> a(k, 0); 
        for (int i = 0; i < t; i++) {
            a[i] = n / t; 
        }
        for (int i = t; i < k; i++) {
            a[i] = 1; 
        }
        
        for (int i = 0; i < k; i++) {
            cout << a[i] << " \n"[i == k - 1]; 
        }
    }
    
    return 0;
}


/*

1497C2k个正数的总和是n并且lcm小于等于二分之n

lcm 最小公倍数


如果是简单的均匀分配: 
1
11 3 

4 4 3
结果就是 12 

5 5 1 就是 5 

所以可以发现，构造的方法是，将所有的位置填充 1 之后 
然后让一部分元素变为相同的值

--- main_test
还是不对

首先输出 k - 3 个 1 
然后，对于剩下的 n， k 恒等于 3

当 n 为奇数的时候，输出 n-1/2, n-1/2, 1
当 n 为偶数但是不可以被 4 整除的时候, 输出 2, n / 2 - 1, n / 2 - 1; 
    2: 2, 0, 0; 
    6: 2, 2, 2; (奇数个 2，第一位用一个，剩下两个)
当 n 可以被 4 整除的时候 n / 2, n / 4, n / 4; 
    8: 4, 2, 2 
    

*/