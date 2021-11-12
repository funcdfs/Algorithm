#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 210, INF = 1e8;

int n, m, q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0; // 把所有的 d[i][i] 初始化为 0
            else d[i][j] = INF;      // 其余的距离全部初始化为无穷大
        }
    }
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);   // 如果存在多条边的话，只保留长度最小的边
    }
    
    floyd();
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        int t = d[a][b];
        if (t > INF / 2) {
            cout << "impossible" << endl;
        } else {
            cout << t << endl;
        }
    }
    
    return 0;
}
