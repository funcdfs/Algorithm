#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std; 

int n, m; 

int work(vector<int> h) {
    int n = h.size(); 
    vector<int> left(n, 0); 
    vector<int> right(n, 0); 
    stack<int> stk; 
    
    for (int i = 0; i < n; i++) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop(); 
        if (stk.size() == 0) {
            left[i] = 0; 
        } else {
            left[i] = stk.top() + 1; 
        }
        stk.push(i); 
    }
    
    stk = stack<int>(); 
    for (int i = n - 1; i >= 0; i--) {
        while (stk.size() && h[stk.top()] >= h[i]) stk.pop(); 
        if (stk.size() == 0) {
            right[i] = n + 1; 
        } else {
            right[i] = stk.top() + 1; 
        } 
        stk.push(i); 
    }
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans = max(ans, (right[i] - left[i] - 1) * h[i]); 
    }
    return ans; 
}

int main() {
    cin >> n >> m; 
    
    vector<vector<char>> g(n, vector<char>(m)); 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j]; 
        }
    }
    
    vector<vector<int>> s(n, vector<int>(m, 0)); 
    for (int i = 0; i < m; i++) {
        if (g[0][i] == 'F') {
            s[0][i] = 1; 
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'F') {
                s[i][j] = s[i - 1][j] + 1; 
            } else {
                s[i][j] = 0; 
            }
        }
    }
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans = max(ans, work(s[i])); 
    }
    
    cout << ans * 3 << endl; 
        
    return 0; 
}

