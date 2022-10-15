#include <iostream>

using namespace std; 

int qmi(int a, int b, int p) {
    // calculate (a ^ b) mod p 
    int ans = 1 % p; 
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = (int64_t)ans * a % p; 
        } 
        a = (int64_t)a * a % p; 
    } 
    return ans; 
}

int main() {
    int a = 0, b = 0, c = 0; 
    cin >> a >> b >> c; 
    cout << qmi(a, b, c) << '\n'; 
    return 0; 
}