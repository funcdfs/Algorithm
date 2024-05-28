// URL: https://codeforces.com/contest/1406/problem/B
// NAME: B. Maximum Product, Codeforces - Codeforces Round #670 (Div. 2)
// LIMIT: 512 MB, 2000 ms
// DATE: 2022-08-18 22:55:25

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        int64_t mn[6] = {}, mx[6] = {}; 
        mn[0] = mx[0] = 1; 
        for (int i = 1; i <= 5; i++) {
            mx[i] = -1e18; 
            mn[i] = 1e18; 
        } 
        
        for (int i = 0; i < n; i++) {
            int x = a[i];   
            // 每获得一个新的元素，就根据这个新的元素更新一遍只选取5 个位置可以得到的最大价值
            for (int j = 5; j > 0; j--) {
                if (x >= 0) {
                    if (mx[j - 1] != -1e18) {
                        mx[j] = max(mx[j], mx[j - 1] * x); 
                    } 
                    if (mn[j - 1] != 1e18) {
                        mn[j] = min(mn[j], mn[j - 1] * x); 
                    }
                } else {
                    if (mn[j - 1] != 1e18) {
                        mx[j] = max(mx[j], mn[j - 1] * x); 
                    }  
                    if (mx[j - 1] != -1e18) {
                        mn[j] = min(mn[j], mx[j - 1] * x); 
                    }
                }
            }  
        }
        
        cout << mx[5] << "\n"; 
    }

    return 0;
}

/*

1406B选择5个数字使得乘积最大

输出这个最大乘积是多少


呆子做法： 
    排序之后，五个最左侧的，三个最左侧的两个最右侧的，四个最左侧的一个最右侧的 
    求最大值 
https://004-so-vegetable.blog.luogu.org/cf1406b


聪明小子: 
    使用 DP 
    记录前 5 个位置可以得到的最大价值 
    每获得一个新的元素，就使用这个新的元素更新选取 5 个位置可以得到的最大的价值

jiangly: 
https://codeforces.com/contest/1406/submission/92587718


*/