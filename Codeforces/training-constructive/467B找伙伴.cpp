// LINK: https://codeforces.com/contest/467/problem/B
// NAME: B. Fedor and New Game, Codeforces - Codeforces Round #267 (Div. 2)
// DATE: 2022-09-06 11:10:32, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    
    vector<int> players(0, 0);
    for (int i = 0; i < m + 1; i++) {
        int x = 0; 
        cin >> x; 
        players.push_back(x);
    }
    
    int fedor = players.back();
    players.pop_back();
    
    
    function<int(int)> binaryCnt = [](int x) -> int {
        int ans = 0;
        while (x > 0) {
            ans += (x & 1);
            x >>= 1;
        }
        return ans;
    };
    
    int ans = 0;
    for (int i = 0; i < players.size(); i++) {
        if (binaryCnt(players[i] ^ fedor) <= k) {
            ans++;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}


/*

467B找伙伴

![467B找伙伴](https://raw.githubusercontent.com/psychonaut1f/a/main/img/konng0120-note-2022-09-06-11-31-48.png)

*/