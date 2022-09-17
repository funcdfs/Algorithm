// LINK: https://codeforces.com/contest/1365/problem/B
// NAME: B. Trouble Sort, Codeforces - Codeforces Round #648 (Div. 2)
// DATE: 2022-09-09 11:29:04, LIMIT: 256 MB, 1000 ms

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
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        vector<int> b(n, 0); 
        
        for (int i = 0; i < n; i++) cin >> a[i]; 
        for (int i = 0; i < n; i++) cin >> b[i]; 
        
        function<bool()> trans = [&a, &b, &n]() -> bool {
            int cnt0 = count_if(b.begin(), b.end(), [](int x) { return x == 0; }); 
            int cnt1 = count_if(b.begin(), b.end(), [](int x) { return x == 1; }); 
            
            if (cnt0 == n || cnt1 == n) {
                for (int i = 0; i + 1 < a.size(); i++) {
                    if (a[i] > a[i + 1]) {
                        return false; 
                    }
                } 
            } 
            
            return true; 
        }; 
        
        if (trans()) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
    
    return 0;
}


/*

1365B每次交换两个相同类型的数字是否可以使得整个数组有序


只要 0 1 都出现过，那么就可以实现全部位置随便打乱 
就是利用一个异 种类的作为中间商， a b c 例如 a 和 c 是 0 种类，b 是 1 种类
a 和 b 先交换，    b a c 
然后 b 和 c 再交换 c a b 
然后 a 和 b 交换， c b a  


*/