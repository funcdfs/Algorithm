#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> f(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j - 1] < a[i - 1]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    
    cout << *max_element(f.begin(), f.end()) << endl;
    
    return 0;
}