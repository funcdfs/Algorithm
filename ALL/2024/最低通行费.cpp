#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

using namespace std;

int main() {
    int n = 0;
    cin >> n; 
    vector a(n + 1, vector<int>(n + 1, 0));
    vector f(n + 1, vector<int>(n + 1, INT32_MAX));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    f[1][1] = a[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > 1){
                f[i][j] = min(f[i][j], f[i - 1][j] +a[i][j]);
            } // 只有不在第一行的时候，才可以从上面过来
            if (j > 1) {
                f[i][j] = min(f[i][j], f[i][j - 1] + a[i][j]);
            } // 只有不在第一列的时候，才可以从左边过来
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
