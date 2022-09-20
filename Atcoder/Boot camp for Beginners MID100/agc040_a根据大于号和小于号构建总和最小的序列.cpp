// LINK: https://atcoder.jp/contests/agc040/tasks/agc040_a
// NAME: A - ><, AtCoder - AtCoder Grand Contest 040
// DATE: 2022.09.19 17:14:30, LIMIT: 1024 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    string s = ""; 
    cin >> s; 
    
    int64_t ans = 0; 
    int n = s.size();  
    vector<int> a(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '<') {
            a[i] = a[i - 1] + 1; 
        }
    }
    dbg(a); 
    vector<int> b(n + 1, 0); 
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '>') {
            b[i] = b[i + 1] + 1; 
        }
    }
    dbg(b); 
    for (int i = 0; i <= n; i++) {
        ans += max(a[i], b[i]); 
    }
    cout << ans << '\n'; 
    return 0;
}


/*

根据大于号和小于号构建总和最小的序列

如果是左括号的话, 那么 ai < a{i + 1}
如果是右括号的话, 那么 ai > a{i + 1}

构建一个 n 个数字的序列，使得总和最小

每一段都从 0 开始 

0 1 2 3 2 1 0 1 2 3 ... 
这种想法是错误的，因为可能边界可以重复利用，例如 0 2 1 0 


所以可以正向遍历，求得满足小于号的最小的方式
还可以反向遍历，球的满足大于号的最小的方式
由于可能发生冲突的点只可能存在于边界处
所以边界处的值变大不会影响前面的内容
所以将边界处取两种情况的最大值，剩下的地方取 a 和 b 中的部分即可

由于 a 有值的地方一定 b 对应的地方是 0 

所以可以统一简写为  

ans += max(a[i], b[i]); 

*/