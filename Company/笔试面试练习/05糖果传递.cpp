#include <iostream>
#include <algorithm>

using namespace std; 

typedef long long LL; 
const int N = 1e6 + 10; 

int n; 
int a[N];

LL s[N]; // 存储前缀和 
LL c[N]; // 存储 x 减去的常数数组 

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i]; 

    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i]; 

    LL avg = s[n] / n; 
    int k = 0; 
    for (int i = 1; i < n; i++) {
        c[k++] = i * avg - s[i]; 
    } // 前 n - 1 项 
    c[k++] = 0; // 最后一项等于 0 
    
    // 接下来就是货仓选址问题 
    
    nth_element(c, c + k / 2, c + k); 

    LL ans = 0; 

    for (int i = 0; i < k; i++) {
        ans += abs(c[i] - c[k / 2]); 
    }

    cout << ans << endl; 

    return 0; 
}