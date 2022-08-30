#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

int getSuit(vector<int>& a, int x) {
    int ans = -1; 
    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= x) {
            ans = a[i]; 
        }
    } 
    
    if (ans == -1) {
        return *min_element(a.begin(), a.end()); 
    } 
    
    return ans; 
}

int cal(vector<int>& a, int n) {
    vector<int> ori(0, 0); 
    while (n > 0) {
        ori.push_back(n % 10); 
        n /= 10; 
    } 
    reverse(ori.begin(), ori.end()); 
    debug(a, ori);
    int maxValue = *max_element(a.begin(), a.end()); 
    
    vector<int> ans(ori.size(), 0);  
    int idx = 0; 
    for (int i = 0; i < ori.size(); i++) {
        int t = getSuit(a, ori[i]); 
        debug(i, t); 
        if (t < ori[i]) {
            ans[i] = t; 
            idx = i; 
            break; 
        } else if (t == ori[i]) {
            ans[i] = t; 
            continue; 
        } else if (t > ori[i]) {
            // 数组中的所有的元素都大于 这个 位置的数字 
            int f = maxValue; 
            for (int l = 0; l < ori.size() - 2; l++) {
                f = f * 10 + maxValue; 
            }
            return f; 
        }
    } 
    
    for (int i = idx + 1; i < ans.size(); i++) {
        ans[i] = maxValue; 
    }
    debug(ans); 
    
    int f = ans[0]; 
    for (int i = 1; i < ans.size(); i++) {
        f = f * 10 + ans[i]; 
    } 
    return f; 
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    
    int x = 0; 
    vector<int> a(0, 0); 
    while (cin >> x) {
        a.push_back(x); 
    } 
    
    cout << cal(a, n) << "\n"; 
    
    // 数组中的数字组成的小于 n 个最大的整数  
    
    return 0;
}


/*



*/