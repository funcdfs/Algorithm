#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n = 0; 
    cin >> n; 
    vector<int> p(n + 1, 0); 
    vector<int> f(n + 1, 0); 
    vector<int> g(n + 1, 0); 
    
    for (int i = 1; i <= n; i++) cin >> p[i]; 
    
    for (int i = 2, minValue = p[1]; i <= n; i++) {
        f[i] = max(f[i - 1], p[i] - minValue); 
        minValue = min(minValue, p[i]); 
    }
    
    for (int i = n - 1, maxValue = p[n]; i >= 1; i--) {
        g[i] = max(g[i + 1], maxValue - p[i]); 
        maxValue = max(maxValue, p[i]); 
    }
    
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i]); 
    }
    cout << ans << endl; 
    
    return 0; 
}