// 思路： 依次枚举删除每个点之后的最大值，求最大值集合中的最小值
#include <iostream>
#include <string.h>

using namespace std;

const int N = 1e5 + 10, M = N * 2;
// n 个点， M 个 边

int n;
int head[N], e[M], ne[M], idx;
// 用单链表数组存储图

int ans = N;
bool nodeStates[N]; 
// ans 初始化为 N ，nodestates 存储节点是否被用过

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}
// 将一个点 b 插入到 a 对应链表的后面，e[idx] = b, ne[idx] = head[a], head[a] = idx++;


int dfs(int u) {
    nodeStates[u] = true;
    // 代表当前点已经被搜索过了
    
    int nodeSum = 0, maxTreeSize = 0;
    
    
    // 对于每一个节点，遍历它的所有出边
    for (int i = head[u]; i != -1; i = ne[i]) {
        int nowNode = e[i];
        
        if (nodeStates[nowNode] == false) {  // 如果出边中的一个点没有被遍历过
            int subTreeSum = dfs(nowNode);   // 递归计算子树的和
            nodeSum += subTreeSum;           // 当前节点的和，累加所有出边计算得到的和

            maxTreeSize = max(maxTreeSize, subTreeSum);
            // 对于删除某点之后的，下面的，所有子树， 都要更新一次 maxTreeSize 
        }
    }
    
    maxTreeSize = max(maxTreeSize, n - nodeSum - 1);
            // 对于删除某点之后的，上面的，其他子树， 再更新一次，maxTreeSize

    ans = min(ans, maxTreeSize);             // ans 等于每次更新最大值过程中的最小值
    return nodeSum + 1;                      // 如果递归执行的话 当前使用的这一个点应该也算作连通块中的一个成员
}

int main() {
    cin >> n;
    memset(head, -1, sizeof head);           // 初始化单链表时是 head = -1, idx = 0, 所以需要将 head 数组先全部初始化为 -1
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);                // 由于无向图，所以需要对于 a 和 b 需要存储两条边
    }
    
    dfs(1);
    // 随便选一个点开始搜索，因为数据 n 大于等于 1， 所以可以满足所有情况的写法就是从第一个点开始搜索
    cout << ans << endl;
    
    return 0;
}

// https://www.acwing.com/activity/content/code/content/1528450/