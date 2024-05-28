#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
#define LL long long
/*2021-07-04-19-41*/
int n;
int a[N], s[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        s[a[i]]++;
        while (j < i && s[a[i]] > 1) {
            s[a[j]]--;  // 注意这里，妙蛙种子
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1415615/