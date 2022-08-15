// Problem: 等式
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1111/
// date: 2022-07-26 13:34:27
// Memory Limit: 64 MB
// Time Limit: 1000 ms
#include <iostream>
#include <cstring>

using namespace std; 

const int N = 1010; 
typedef long long LL; 

/*
longlong 可以存储 2^18 
2^50 相当于 10^15
*/

int n;
LL m; 
LL a[N]; 
LL s[60][2]; 

LL get_min(int i) {
    // 每一个位置取最小值的话，值是多少 
    LL ans = 0; 
    for (int k = i; k >= 0; k--) {
        ans += min(s[k][0], s[k][1]);  
    } 
    return ans; 
}

int main() {
    int T; 
    cin >> T; 
    
    for (int C = 1; C <= T; C++) {
        cin >> n >> m; 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        memset(s, 0, sizeof s); 
        for (int i = 0; i < 50; i++) { 
            // 从前往后枚举一下每一位, 第 0 位到第 49 位
            for (int j = 0; j < n; j++) {
                // 每一位枚举一下所有的数字， （k 的第 i 位和这个数字的第 i 位） 
                // 看一下，第 i 位填 0 的话，总和是多少，填 1 的话总和是多少
                if (a[j] >> i & 1) {     // 如果 a[j] 的 第 i 个数位是 1的话
                    s[i][0] += 1ll << i; // 也就是 k 的第 i 位需要取 0，才可以把这一位加上 (取 1 的话，是 0，加上没有意义)
                } else {
                    s[i][1] += 1ll << i; 
                }
            }
        }
        // s[i][0]: 若 k 的第 i 位取 0，则 (A1^k)_i + (A2^k)_i + (An^k)_i
        // s[i][1]: 若 k 的第 i 位取 1，则 (A1^k)_i + (A2^k)_i + (An^k)_i
        // 现在就得到了预处理的 s 数组，表示对于每一个数位，取 0 或者取 1 得到的，每个数字的，对应位上的，和

        // s[0][0] s[0][1] 
        // s[1][0] s[1][1] 
        // s[2][0] s[2][1] 
        // ...
        // s]49][0] s[49][0]

        // 也就是需要在每一行中，选并且只选择一个数字

        LL ans = 0, sum = 0;
        if (get_min(49) > m) ans = -1; 
        else {
            for (int i = 49; i >= 0; i--) {
                // 如果说这个位置取 1，并且后面的任务依然可以完成，就取 1 
                // sum 代表之前得到的和，s[i][1] 代表当前得到的和，get_min(i - 1) 代表之后得到的和
                if (sum + get_min(i - 1) + s[i][1] <= m) {
                    ans += 1ll << i; // 第 i 位选 1 
                    sum += s[i][1];  
                } else {
                    sum += s[i][0]; 
                }
            }   
        }
        
        printf("Case #%d: %lld\n", C, ans); 
    }
    
}


/*
求出，使得 "a[i]^k 的和小于等于 M 的最大的 k 是多少"

贪心解决： 
    如果高位可以填充 1，则填 1，因为低位无论多少个 1 都不能比过高位的 1 
    因为这个题要求保证找到满足要求的 k 尽可能大，所以不能随便填写 1 导致低位全填最小值都比 M 大了
        如果这个高位可以选 1，就选 1 
        如果不能选 1，就乖乖地选 0 

将每一位取 0 或者取 1 的结果存储到数组中进行记录 

写一个函数记录取后置位结果之和的最小值
*/