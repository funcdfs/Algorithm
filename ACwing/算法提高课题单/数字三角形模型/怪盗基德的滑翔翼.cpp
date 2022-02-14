#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int n = 0;
        cin >> n;
        vector<int> a(n + 1, 0);
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (a[i] > a[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        int ans = *max_element(f.begin(), f.end());
        
        for (int i = n; i >= 1; i--) {
            f[i] = 1;
            for (int j = n; j > i; j--) {
                if (a[i] > a[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        ans = max(ans, *max_element(f.begin(), f.end()));
        
        cout << ans << endl;
    }
    
    return 0;
}