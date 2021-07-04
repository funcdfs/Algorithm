#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int n, m, x;

// 这两个数组是升序排序的
bool check(int i, int j) {
    if (a[i] + b[j] == x)
        return true;
    else
        return false;
}
int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (a[i] + b[j] == x){
    //             cout << i << ' ' << j;
    //         }
    //     }
    // }
    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
    }
    return 0;
}