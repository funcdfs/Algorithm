// LINK: https://codeforces.com/contest/1334/problem/C
// NAME: C. Circle of Monsters, Codeforces - Educational Codeforces Round 85 (Rated for Div. 2)
// DATE: 2022.09.14 17:09:48, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int64_t> a(n, 0); 
        vector<int64_t> b(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i]; 
        
        int64_t ans = 0; 
        
        for (int i = 1; i < n; i++) {
            if (a[i] > b[i - 1]) {
                ans += a[i] - b[i - 1]; 
                a[i] = b[i - 1]; 
            }
        }
        if (a[0] > b.rbegin()[0]) {
            ans += a[0] - b.rbegin()[0]; 
            a[0] = b.rbegin()[0]; 
        }
        
        debug(a); 
        debug(b); 
        debug(ans); 
        
        int64_t minVal = numeric_limits<int64_t>::max(); 
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue; 
            minVal = min(minVal, a[i]); 
        } 
        
        cout << ans + minVal << '\n'; 
    }
    
    return 0;
}


/*

1334C手枪消灭怪物圈

实例：
![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914224137.png)

怪兽的血量是恒定的，为了最小化小手枪造成的伤害，就要最大化爆炸的伤害 

如何最大化爆炸的伤害： 
    能炸死的就直接炸死，不能炸死就打到残血直到刚刚好可以被炸死

假设当前怪兽的血量是 a，上一个怪兽的爆炸的伤害是 b 
如果 a <= b 那么他可以被上一个怪兽一次性炸死
如果 a >  b 上一个怪兽炸不死他，而他剩下的血量就必须要用小手枪去打，所以至少要对他先打 b - a 次



现在处理之后就得到了一个环，因为每一个怪兽的血量都足够低，以至于可以被上一个怪兽打死

所以现在只需要打死任何一个怪兽，剩下的所有的怪兽都会连环爆炸，然后游戏直接结束 
所以现在，只需要选择，处理之后的剩余血量最少的一个，干掉他，然后触发连锁反应

*/