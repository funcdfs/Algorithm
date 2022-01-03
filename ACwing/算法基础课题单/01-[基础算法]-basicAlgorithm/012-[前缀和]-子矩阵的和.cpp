// 输入子矩阵的左上角坐标和右下角坐标。输出子矩阵中石油数字的和

#include <iostream>
using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], s[N][N];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = a[i][j] + s[i - 1][j] 
                    + s[i][j - 1] 
                    - s[i - 1][j - 1];
    // 构建前缀和
    
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = s[x2][y2]
                    - s[x1 - 1][y2]
                    - s[x2][y1 - 1]
                    + s[x1 - 1][y1 - 1];
        cout << ans << endl;
    }
    
    return 0;
}


// https://www.acwing.com/activity/content/code/content/1415612/