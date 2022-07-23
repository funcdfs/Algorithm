#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n = 0; 
    cin >> n; 
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    } 
    
    vector<int> left(n, 0); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                left[i] = max(left[i], left[j] + 1); 
            }
        }
    }
    vector<int> right(n, 0); 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) {
                right[i] = max(right[i], right[j] + 1); 
            }
        }
    }
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i] + right[i] + 1); 
    } 
    cout << n - ans << endl; 
    
    return 0; 
}