#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110; 
int n; 
int a[N]; 

int main() {
    cin >> n;
    int sum = 0; 
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i]; 
    
    int ans = 0; 
    int avg = sum / n; 
    
    for (int i = 0, x = 0; i < n; i++) {
        x = a[i] - avg + x; 
        if (x != 0) ans++; 
    }
    
    cout << ans << endl; 
    
    return 0;
} 