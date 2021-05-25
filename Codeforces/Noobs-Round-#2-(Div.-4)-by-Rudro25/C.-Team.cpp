#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define PSB push_back
#define ll long long
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
constexpr ll mod = 1e9 + 7;
const ll N = 3e6 + 5;

int main() {
    FastIO

        int test;
    cin >> test;
    //读入测试数据组数：要测试几组数据
    while (test--) {
        int n, k, team = 0;
        cin >> n >> k;
        // n个人，最大值为k
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        //读入每一个team数据并完成排序
        //数据类型用ll
        for (ll l = 0, r = n - 1; l <= r;) {
            // r为数组下标
            if (a[r] >= k) {
                ++team;
                --r;
                //逻辑相同，但是用了一次for循环完成
            } else if (a[r] + a[l] >= k && l != r) {
                ++team;
                ++l;
                --r;
            } else
                l++;
        }
        cout << team << endl;
    }

    return 0;
}