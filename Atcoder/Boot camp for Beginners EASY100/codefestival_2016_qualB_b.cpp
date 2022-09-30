// LINK: https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b
// NAME: B - Qualification simulator, AtCoder - CODE FESTIVAL 2016 qual B
// DATE: 2022.09.13 22:38:38, LIMIT: 256 MB, 2000 ms

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
    
    int n, a, b; 
    cin >> n >> a >> b; 
    string s = ""; 
    cin >> s; 
    
    vector<int> pos(0, 0); 
    unordered_map<int, int> hs; 
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'b') {
            pos.push_back(i); 
            hs[i] = pos.size(); 
        }
    }
    
    int passed = 0; 
    
    for (int i = 0; i < (int)s.size(); i++) {
        bool ok = false; 
        if (s[i] == 'a' && passed < a + b) {
            // jp student 
            cout << "Yes\n"; 
            ok = true;
            passed++; 
        } else if (s[i] == 'b' && passed < a + b) {
            // oversea student
            if (hs[i] <= b) {
                cout << "Yes\n"; 
                ok = true; 
                passed++; 
            }
        } 
        if (ok == false) {
            cout << "No\n"; 
        }
    }
    
    return 0;
}


/*

日本学生和留学生

https://atcoder.jp/contests/code-festival-2016-qualb/submissions/34841418

*/