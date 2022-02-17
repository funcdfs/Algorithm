// Problem: 1260：【例9.4】拦截导弹(Noip1999)
// Contest: SSOIER
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1260
// date: 2022-02-14 18:54:27
// Memory Limit: 65 MB
// Time Limit: 1000 ms

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int q[N];
int f[N], g[N];

int main() {
    while (cin >> q[n]) n++;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (q[j] >= q[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    
    cout << ans << endl;
    // 输出一个拦截导弹的设备最多可以拦截多少导弹
    // 也就是求最长非严格单调下降的子序列 （导弹系统只可以攻击同阶级或者更加小的）
    
    // 第二问： 输出少需要几个导弹系统可以防御所有导弹
    // 贪心策略
    // 放入每一个导弹的时候，找出最小值大于当前值中的最小的元素，拼接在后面
    // 否则新开辟一个区间
    
    TODO: 拦截导弹，贪心
    
    cout << cnt << endl;
}