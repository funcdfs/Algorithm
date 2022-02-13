// Problem: P2249 【深基13.例1】查找
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2249
// date: 2022-02-09 12:30:21
// Memory Limit: 125 MB
// Time Limit: 1000 ms

/* @ https://github.com/fengwei2002/Algorithm */

#include <algorithm>
#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f
typedef long long LL;

using namespace std;

const int N = 1e6 + 10;
int n, k;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入非严格单调递增的数组
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    while (k--) {
        int x = 0;
        cin >> x;
        // 二分查找 x 出现的第一个位置
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) {  // 条件是大于等于，找到满足大于等于的最左侧的点
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (a[r] == x)
            cout << r + 1 << ' ';
        else
            cout << "-1" << ' ';
    }

    return 0;
}
