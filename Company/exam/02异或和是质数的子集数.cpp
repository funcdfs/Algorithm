#include <iostream>

using namespace std; 

const int N = 5010; 
const int M = 8192; 
const int MOD = 1e9 + 7; 

int n; 
int a[N];
int f[2][M]; 

bool isPrime(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            return false; 
        }
    }
    return true; 
} 

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++) cin >> a[i]; 
    
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < M; j++) {
            f[i & 1][j] = (f[(i - 1) & 1][j] + f[(i - 1) & 1][j ^ a[i]]) % MOD;
        }
    }
    
    int ans = 0; 
    
    for (int i = 2; i < M; i++) {
        if (isPrime(i)) {
            ans = (ans + f[n & 1][i]) % MOD; 
        }
    }
    
    cout << ans << endl; 
    
    return 0;
}