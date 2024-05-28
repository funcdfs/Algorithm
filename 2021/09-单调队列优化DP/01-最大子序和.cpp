// LINK: https://www.acwing.com/problem/content/137/
// NAME: 最大子序和, AcWing
// CODE: https://github.com/fengwei2002, 2022.11.18-18:17:16, 1000 ms

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n = 0, m = 0; 
    cin >> n >> m; 
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    vector<int> s(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1]; 
    }
    
    int64_t ans = -2e18; 
    deque<int> que; 
    que.push_back(0); 
    for (int i = 1; i <= n; i++) {
        while (!que.empty() && i - que.front() > m) {
            que.pop_front(); 
        }
        ans = max(ans, (int64_t)s[i] - s[que.front()]); 
        while (!que.empty() && s[que.back()] >= s[i]) {
            que.pop_back(); 
        }
        que.push_back(i); 
    }
    cout << ans << '\n';
    
    return 0; 
}


/*
![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/%E6%A8%AA%E7%89%88%E8%8D%89%E7%A8%BF%E7%BA%B8%20P5.png)

子序列中的总和最大 长度不能超过 m 



*/