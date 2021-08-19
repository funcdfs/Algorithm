#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-08-14-18-06*/

const int N = 4;
int a[N][N];
// 126
// 35
// 4
int main() {
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 3;
    a[3][1] = 4;
    int i = 2, j = 2;
    bool up = true;
    while (i <= N) {
        while (j <= N) {
            if (up == true) {
                a[i][j] = a[i + 1][j - 1] + 1;
                if (i == 1) {
                    j++;
                    up = !up;
                }
            }
            if (up == false) {
                a[i][j] = a[i - 1][j + 1] + 1;
                if (i == 1) {
                    i++;
                    up = !up;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << a[i][j] << " ";
        }
        puts("");
    }
    // cout << a[3][3] << endl;
    return 0;
}