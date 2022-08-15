#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std; 

int main() {
    int n = 0; 
    while (cin >> n, n != 0) {
        vector<int> h(n, 0); 
        for (int i = 0; i < n; i++) cin >> h[i]; 
        vector<int> left(n, 0); 
        vector<int> right(n, 0); 
        stack<int> stk; 
        
        for (int i = 0; i < n; i++) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                stk.pop(); 
            }
            if (stk.size() == 0) {
                left[i] = 0; 
            } else {
                left[i] = stk.top() + 1; 
            }
            stk.push(i); 
        }
        
        stk = stack<int>(); 
        
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && h[stk.top()] >= h[i]) {
                stk.pop(); 
            }
            if (stk.size() == 0) {
                right[i] = n + 1; 
            } else {
                right[i] = stk.top() + 1; 
            }
            stk.push(i); 
        }
        
        long long ans = 0; 
        
        for (int i = 0; i < n; i++) {
            ans = max(ans, (long long)(right[i] - left[i] - 1) * h[i]); 
        }
        cout << ans << endl; 
    }
    
    return 0; 
}