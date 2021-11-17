// 链接：https://www.acwing.com/activity/content/code/content/1625773/

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int len = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);  // 更新一下，最长子序列的长度
        q[r + 1] = a[i];        // 更新对应长度结尾的最小值
    }

    printf("%d\n", len);

    return 0;
}