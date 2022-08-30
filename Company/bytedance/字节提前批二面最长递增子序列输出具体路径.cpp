#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    vector<int> f(n + 1, 1); 
    vector<int> g(n + 1, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    } 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i - 1] > a[j - 1]) {
                if (f[i] < f[j] + 1) {
                    f[i] = f[j] + 1; 
                    g[i] = j; 
                }
            }
        }
    } 
    
    int maxLen = *max_element(f.begin(), f.end()); 
    int k = find(f.begin(), f.end(), maxLen) - f.begin(); 
    
    vector<int> path; 
    for (int i = 0; i < maxLen; i++) {
        path.push_back(a[k - 1]); 
        k = g[k];
    }
    
    reverse(path.begin(), path.end()); 
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i == path.size() - 1]; 
    }
    
    return 0; 
}