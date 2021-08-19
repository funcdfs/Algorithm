/*2021-08-06-11-46*/

/* tags: 贪心
 * n个男人和 n 个女人，下标都是 1 - n
 * 每个女的有一份他所喜欢的男人的下标列表。
 * 我们按照这样的贪心规则包办婚姻：每个女的选择他的列表中下标最小且没有被其他女人选择过的男人结婚，
 * 如果不存在这样的男人就不结婚。你现在可以尝试给某一个女人的喜欢列表加上一个不在列表中的男人下标，问是否能够提高包办婚姻成功的次数
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
const int null = 0x3f3f3f3f;

#define LL long long
#define ULL unsigned long long
#define PB push_back
#define FastIO               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
void solve() {}

int main() {
    FastIO int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
