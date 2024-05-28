// LINK: https://codeforces.com/contest/230/problem/B
// NAME: B. T-primes, Codeforces - Codeforces Round #142 (Div. 2)
// DATE: 2022.09.15 20:49:11, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

bool isPrime(int64_t x) {
    if (x < 2) {
        return false;  // 判断是否大于 1
    }
    for (int i = 2; i * i <= x; i++) {
        // 判断从 2 到 i - 1 是否包含 n 的约数，是的话，返回 false， 否则返回 true
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0; 
    cin >> n; 
    vector<int64_t> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    for (int i = 0; i < n; i++) {
        if (sqrt(a[i]) != (int)sqrt(a[i])) {
            cout << "NO\n"; 
            continue;
        }
        if (isPrime(sqrt(a[i]))) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        } 
    }
    
    return 0;
}

/*

230B判断每一个数字是不是三个质数的乘积

如果一个数字是三个质数的乘积，那么他一定是一个质数的平方


example:
    使用 Yes << endl 会超时，而使用 YES\n 就不会超时

*/