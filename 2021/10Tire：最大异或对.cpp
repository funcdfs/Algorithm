#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010, M = 3100010;

int n;
int a[N], son[M][2], idx;

void insert(int x) {
    int p = 0;  //根节点
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        // 取 X 的第 i 位的二进制数是什么  x >> k & 1(前面的模板)
        if (!son[p][u])
            son[p][u] = ++idx;  ///如果插入中发现没有该子节点,开出这条路
        p = son[p][u];  //指针指向下一层
    }
}

int search(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {  
        //从最大位开始找
        int u = x >> i & 1; 
        // x 的第 i 为表示额二进制是什么
        if (son[p][!u]) {  
            //如果当前层有对应的不相同的数
            // res += 1 << i; 阴间写法，看不懂
            res = res << 1 + 1;
            // 左移一位空出最后一个元素应该存放的位置 (*2)
            // 在加上点值就是应该得到的路径了
            p = son[p][!u]; // p 指针就指到不同数的地址
        } else{
            res = res << 1 + 0;
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    scanf("%d", &n);
    // 读入数字 n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    // 将 i 个不同的数字插入到二进制 tire 树中

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, search(a[i]));
    // 对每一个数字搜寻最大值
    printf("%d\n", res);

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1512190/