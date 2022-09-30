// LINK: https://codeforces.com/contest/1381/problem/A1
// NAME: A1. Prefix Flip (Easy Version), Codeforces - Codeforces Round #658 (Div. 1)
// DATE: 2022-09-09 19:02:36, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

void flip(char& c) {
    if (c == '1') {
        c = '0'; 
    } else if (c == '0') {
        c = '1'; 
    }
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int n = 0; 
        cin >> n; 
        string a = "", b = ""; 
        cin >> a >> b; 
        
        a = " " + a, b = " " + b; 
        vector<int> path; 
        
        for (int i = n; i >= 1; i--) {
            if (a[i] == b[i]) {
                continue; 
            } 
            if (a[1] == b[i]) {
                flip(a[1]); 
                path.push_back(1); 
            } 
            path.push_back(i); 
            
            for (int j = 1; j <= i; j++) {
                flip(a[j]); 
            } 
			for (int j = 1, k = i; j < k; j++, k--) {
			    swap(a[j], a[k]); 
			} // reverse 1 to i
        } 
        
        cout << path.size() << ' '; 
        if (path.size() == 0) {
            cout << "\n"; 
            continue; 
        }
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " \n"[i == path.size() - 1]; 
        }
    }
    
    return 0;
}


/*

1381A1输出使得二进制字符串相等的prefix路线

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909194329.png)

*/