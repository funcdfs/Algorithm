// 返回元素的其实位置和结束位置

#include <iostream>

using namespace std;

const int N = 100010;
int n, q;
int a[N];

void cal(int k) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= k) r = mid; // 如果某个值大于目标值，说明要寻找的区间端点在左侧，使用 r = mid 更新边界
        
        else l = mid + 1;
    }
    if (a[l] != k) 
        cout << "-1 -1" << endl;
    else {
        cout << l << ' ';
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= k) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}

int main() {
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (q--) {
        int k = 0;
        cin >> k;
        cal(k);
    }
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1402904/