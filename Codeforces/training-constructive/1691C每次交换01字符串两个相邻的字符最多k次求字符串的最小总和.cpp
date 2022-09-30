// LINK: https://codeforces.com/contest/1691/problem/C
// NAME: 1691C. Sum of Substrings, Codeforces - CodeCraft-22 and Codeforces Round #795 (Div. 2)
// DATE: 2022.09.20 20:36:51, LIMIT: 256 MB, 1000 ms

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
    
    int tt = 0; 
    cin >> tt; 
    
    function<int(string&)> cal = [](string& s) {
        int ans = 0; 
        for (int i = 1; i < (int)s.size() - 1; i++) {
            ans += (s[i] - '0') * 11; 
        } 
        ans += (s[0] - '0') * 10;
        ans += (s.rbegin()[0] - '0') * 1; 
        return ans; 
    };
    
    while (tt--) {
        int n = 0, k = 0; 
        cin >> n >> k; 
        string s = string(n, ' '); 
        cin >> s; 
        int cnt1 = count(s.begin(), s.end(), '1'); 
        int64_t ans = 11 * cnt1; 
        
        int l = -1, r = -1; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (l == -1) l = i; 
                r = i; 
            }
        } 
        r = n - 1 - r; 
        
        if (ans == 0) {
            cout << 0 << '\n'; 
        } else if (ans == 11) {
            if (r <= k) cout << 1 << '\n'; // 可以将这个唯一的 1 放到最后一个位置 -10 
            else if (l <= k) cout << 10 << '\n'; // 可以将这个唯一的 1 放到第一个位置 -1 
            else cout << 11 << '\n'; 
        } else {
            if (l + r <= k) cout << ans - 11 << '\n'; // 如果两个位置都可以替换 
            else if (r <= k) cout << ans - 10 << '\n'; // 只有最后一个位置可以换 -10 
            else if (l <= k) cout << ans - 1 << '\n'; // 只有第一个位置可以换 -1 
            else cout << ans << '\n'; 
        }
    }
    
    return 0;
}


/*

1691C每次交换01字符串两个相邻的字符最多k次求字符串的最小总和


可以观察到每一个 S 

f(s) 可以表示为 
f(s) = 10*s1  + 11*s2 + 11*s3 + 11*s_{n - 1} + 1*sn

        每一个 1 作为 10 位上面的数字的时候，贡献量为 10 
        每一个 1 作为 个位 上面的数字的时候，贡献量为 1 
    所以也就是除去首位和末尾位，中间的所有的数字都被对答案贡献 11 次 

要使得首尾尽量小，总答案就会尽量小， 把中间的 1 和首位的 0 进行交换，总答案会减去 1 
把中间的 1 和末尾的 0 交换，总答案会减去 10 

优先考虑把末尾从 0 变为 1， 然后再考虑把首位从 0 变为 1 
*/