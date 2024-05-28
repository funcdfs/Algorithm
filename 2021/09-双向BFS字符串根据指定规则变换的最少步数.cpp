// LINK: https://www.acwing.com/problem/content/192/
// NAME: 双向BFS字符串根据指定规则变换的最少步数, AcWing
// DATE: 2022-08-22 15:24:55, LIMIT: 64 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int N = 6; 
int n; 
string A, B; 
string a[N], b[N]; 


int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, 
    string a[N], string b[N]) {
    // 扩展一层的话，就是每次把和当前队首元素在同一层的节点全部扩展出来 
    int d = da[q.front()];  
    while (q.size() && da[q.front()] == d) {
        auto t = q.front(); 
        q.pop(); 
        
        // 接下来就是扩展 
        for (int i = 0; i < n; i++) { // 枚举所有的规则
            for (int j = 0; j < t.size(); j++) { // 枚举所有的子串 
                if (t.substr(j, a[i].size()) == a[i]) {
                    string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size()); // 三部分 
                    if (db.count(r)) { // 如果从终点也可以搜到，就可以直接返回了 
                        return da[t] + db[r] + 1; 
                    } 
                    if (da.count(r)) { // r 已经搜过了 不重复搜索
                        continue; 
                    }
                    da[r] = da[t] + 1; 
                    q.push(r); 
                }
            }
        } 
    } 
    
    return 11; // 没有搜到答案的话， 返回一个大于 10 的数字
}


int bfs() {
    if (A == B) return 0; 
    queue<string> qa, qb; 
    unordered_map<string, int> da, db;  
    
    qa.push(A); da[A] = 0; 
    qb.push(B); db[B] = 0; 
    // 两个 BFS 的队列和 两个存储距离的 dist 
    
    int step = 0; 
    while (qa.size() && qb.size()) {
        int t; 
        if (qa.size() < qb.size()) {
            t = extend(qa, da, db, a, b); // 如果第一个队列更短，就先扩展第一个队列
        } else {
            t = extend(qb, db, da, b, a); 
        }
        
        if (t <= 10) {
            return t; 
        } 
        // 如果扩展的过程中找到了到达的距离就直接返回，否则当前层次无解，用 t 保存 
        
        if (++step == 10) {
            return -1; 
        }
    } 
    
    return -1;  
    // 如果任意一个队列为空，说明所有情况都搜完了还没碰面，所以输出无解
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> A >> B; 
    while (cin >> a[n] >> b[n]) n++; 
    
    int t = bfs(); 
    if (t == -1) {
        cout << "NO ANSWER!\n"; 
    } else {
        cout << t << "\n"; 
    }
    
    return 0;
}


/*

给定两个字符串

按照指定规则，如果可以在 10 步之内变过去的话，输出最小的变化次数
如果超过 10 步的话，就输出无解

abcd xyz

1: abc->xu 
2: ud->y
3: y->yz

对于每一个字符串，最多存在 6 种规则变换
字符串长度的上限是 20 
每一次转变的分支会有很多种

如果直接从起点遍历到终点：
    最多遍历 10 步，假设存在 k 个分支
    k^10 个字符串
    
对于这样的空间巨大的题目
可以考虑双向 BFS 的写法

a 和 b 同时找对方，这样空间就会减少非常多 

空间就从 k^10 优化为 2*k^5 


注意：
    每次搜索一层而不是一个点 
    https://www.acwing.com/activity/content/code/content/132167/
*/