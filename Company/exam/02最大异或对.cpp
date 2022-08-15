#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 1e5 + 10;
const int M = 31 * N; // trie 树中的节点的最大的个数
// 每个数字 31 位

int n;
int a[N];
int son[M][2];
int idx; 

void insert(int x) {
    int p = 0; 
    for (int i = 30; i >= 0; i--) { // 从最高位开始 
        int u = x >> i & 1; // 取出 x 的第 i 位二进制表示是什么东西
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u]; 
    }
}

int query(int x) {
    int p = 0;
    int ans = 0;
    
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1; 
        if (son[p][!u]) {
            p = son[p][!u];
            ans = (ans << 1) + !u; 
        } else {
            p = son[p][u];
            ans = (ans << 1) + u;
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        insert(a[i]);
        int t = query(a[i]); // 为了不处理空集的情况，先插入后查询
        ans = max(ans, a[i] ^ t);
    }
    
    cout << ans << endl; 
    
    return 0;
}