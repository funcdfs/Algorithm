// Problem: 区间覆盖
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/909/
// date: 2022-02-12 20:32:58
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int main() {
    int st = 0, ed = 0;
    cin >> st >> ed;

    int n = 0;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }

    sort(a.begin(), a.end(), [&](const PII x, const PII y) {
        return x.first < y.first;
    });

    int ans = 0;
    bool success = false;

    for (int i = 0; i < n; i++) {
        int j = i;
        int r = -2e9;
        while (j < n && a[j].first <= st) {
            r = max(r, a[j].second);
            j++;
        }
        // 在所有左端点小于 start 的区间中，找出右端点最靠右侧的区间

        if (r < st) {
            ans = -1;
            break;
        } // 如果最右侧的区间小于，则说明无解，return 即可

        ans++;
        // 找到了所有包含 start 的点中右端点的最远的元素， ans++

        if (r >= ed) { 
            success = true;
            break; // 如果提前找到了元素就可以 break 了
        }

        // 将开始位置更新为 r
        st = r;
        i = j - 1;
    }

    if (!success) ans = -1;
    cout << ans << endl;

    return 0;
}