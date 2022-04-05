#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n = 0; 
    cin >> n; 
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; 
    }
    
    vector<int> path; 
    vector<vector<int>> ans; 
    vector<bool> st(n, false); 
    
    function<void(int)> dfs = [&](int index) {
        if (index > n) return; 
        ans.push_back(path); 
        
        for (int i = index; i < n; i++) {
            if (st[i] == false) {
                path.push_back(a[i]); 
                st[i] = true; 
                dfs(i); 
                path.pop_back(); 
                st[i] = false; 
            }
        }
    }; 
    
    dfs(0); 
    
    for (auto x : ans) {
        for (auto y : x) {
            cout << y << ' '; 
        }
        cout << endl; 
    }
    
    return 0; 
}