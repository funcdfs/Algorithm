// 山上存在 N 个景点 
// 每次浏览的编号都要大于前一个景点的编号

// 不连续浏览海拔相同的两个景点，开始下山就不往上走了
// 求最多可以浏览多少个景点
// 路径为先上升再下降

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> f(n + 1, 0);
    vector<int> g(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i - 1] > a[j - 1]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (a[i - 1] > a[j - 1]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i] + g[i] - 1);
        // 中间的点值计算一次
    }
    cout << ans << endl;
    
    return 0;
}