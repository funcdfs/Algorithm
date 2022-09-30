// URL: https://codeforces.com/contest/327/problem/A
// NAME: A. Flipping Game, Codeforces - Codeforces Round #191 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-20 09:46:30

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 4
#define dline() 2
#endif
/*----------------------------------*/

int main_n3() {
    cin.tie(0)->sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = accumulate(a.begin(), a.end(), 0);
    int ans = 0; 
    
    for (int i = 0; i < n; i++) { // 枚举起点 
        for (int j = i; j < n; j++) { // 枚举终点
            int s = cnt;  
            for (int k = i; k <= j; k++) { // 枚举每一个起点和终点构成的区间
                if (a[k]) s--; 
                else s++; 
            } 
            
            ans = max(ans, s); 
        }
    }
    
    cout << ans << "\n"; 

    return 0;
}

/*


327A翻转一次01牌面获得最多的1

可以将一个区间中的 0 变为 1， 也可以将 1 变为 0

求一次操作之后的 1 的数量最多的数量


注意
---
1
1
0
---
8
1 0 0 0 1 0 0 0
---
输出的是 7 而不是 5 ，所以不是求最长的 0 序列是多少 

*/

int main_n2() { // O(n^2)
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    vector<int> s(n + 1); 
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1]; 
    int ans = 0; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int cnt1 = s[i] - s[j - 1];  // 计算这个区间中的 1 的个数 
            int cnt0 = i - (j - 1) - cnt1; 
            // 将这个区间 i 到 j 的所有的元素反转等价于 将 1 的数量减去，再加上 0 的数量 
            
            if (s[n] - cnt1 + cnt0 > ans) {
                ans = s[n] - cnt1 + cnt0; 
            }
        }
    } 
    
    cout << ans << "\n"; 
    
    return 0;
}

/*

O(n) 

*/
int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    // 也就是再反转之前，让这段子序列中的 1 尽可能的少，0 尽可能的多 
    // 因此记录 1 到 i 中的 0 的个数为 a[i]， 1 的个数为 b[i] 
    // 维护 a[i] - b[i] 的最大值即可 
    
    // 另一种理解方式, 假定 1 对答案的贡献是 -1 0 对答案的贡献是 1 
    // 最贡献序列求最大的子段和即可，答案是贡献序列的最大子段和和原序列中的 1 的个数之和 
    
    vector<int> f(n); 
    // f[i] 代表结尾是 a[i] 的最大子段和
    
    if (a[0] == 1) {
        f[0] = -1; 
    } else {
        f[0] = 1; 
    } 
    // 初始化 f[0]
    
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) { // 贡献为 1 
            f[i] = max(1, f[i - 1] + 1); 
        } else { // 贡献为 -1
            f[i] = max(-1, f[i - 1] - 1); 
        }
    }
    dbg(f); 
    
    int cnt = accumulate(a.begin(), a.end(), 0); // 原本的 1 的数量 
    int ans = *max_element(f.begin(), f.end());  // 一次操作可以得到的最大贡献
    
    dbg(cnt, ans); 
    
    cout << cnt + ans << "\n"; 
    
    return 0;
}