#include <algorithm>
#include <iostream>
using namespace std;

const int N = 110, M = 11;

int n ,m;
int f[N][M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) f[i][1] = i;
        for (int i = 1; i <= m; i++) f[1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                f[i][j] = f[i][j - 1];
                for (int k = 1; k <= i; k++) {
                    f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
                }
            }
        }
        cout << f[n][m] << endl;
    }
    return 0;
}


#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a = 0;
int main() {

}
