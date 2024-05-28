// https://www.acwing.com/problem/content/2818/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
#define LL long long
/*2021-07-04-19-52*/
int a[N], b[N];

// 子序列指序列的一部分项按原有次序排列而得的序列

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < m; i++) cin >> b[i];
    // int sum = 0;
    // for (int i = 0, j = 0; i < n && j < m;) {
    //     if (a[i] == b[j]) {
    //         sum++;
    //         i++;
    //         j++;
    //     } else {
    //         j++;
    //     }
    // }
    // if (sum == n) {
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }

    // 简写：（当想出来思路之后，不要慌张，慢慢堆砌正确答案）
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) i++;
        j++;
    }
    cout << (i == n ? "Yes" : "No");
    return 0;
}