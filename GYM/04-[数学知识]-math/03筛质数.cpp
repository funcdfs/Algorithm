/* 给定一个正整数，请你求出 1-n 中质数的个数 */

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool st[N];

void getPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i] == false) {  // 如果 2 到 n 中的一个数字没有被筛过的话。说明他是一个质数
            primes[cnt++] = i; // 如果不是质数的话， 加到数表里面

            for (int j = i + i; j <= n; j += i)  { 
                st[j] = true;  // 然后再把每一个数字的倍数删除掉
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    getPrimes(n);
    cout << cnt << endl;
    return 0;
}
// o(n log_n log_n)



// 线性筛法：每一个 n 只会被最小质因子筛掉 ，在 10^7 的数据量的时候，时间加快一倍左右
// -------------------------------------------------------

void getPrimes(int n) {
    for (int i = 2; i <= n; i++) {
        if (st[i] == false) {
            primes[cnt++] = i; // 将这个数加到 数表中
        }

        // 变形一下得到 i * primes[j] <= n，大于 n 的合数筛去也没有意义
        for (int j = 0; primes[j] <= n / i; j++) { // 从小到大枚举所有的质数，质数 > n / i 的时候 break 掉
            st[i * primes[j]] = true;              // 将数表中元素的倍数删除
            if (i % primes[j] == 0) break;         // 第一次成立的时候，primes[j] 是 i 的最小质因子
        }
    }
}