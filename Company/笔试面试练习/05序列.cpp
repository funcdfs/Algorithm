#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std; 

typedef pair<int, int> PII; 

const int N = 2010; 
int m, n; 
int a[N], b[N], c[N]; 
// a 是第一个序列，已经排序
// b 是要和 a 进行合并的序列 
// c 是一个辅助序列，用于存储 a 和 b 合并的结果 


void merge() {
    function<bool(PII&, PII&)> compare = [](PII& a, PII& b) {
        return a > b; 
    }; 
    priority_queue<PII, vector<PII>, function<bool(PII&, PII&)>> heap(compare); 
    // 小根堆#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std; 

typedef pair<int, int> PII; 

const int N = 2010; 
int m, n; 
int a[N], b[N], c[N]; 
// a 是第一个序列，已经排序
// b 是要和 a 进行合并的序列 
// c 是一个辅助序列，用于存储 a 和 b 合并的结果 


void merge() {
    function<bool(PII&, PII&)> compare = [](PII& a, PII& b) {
        return a > b; 
    }; 
    priority_queue<PII, vector<PII>, function<bool(PII&, PII&)>> heap(compare); 
    // 小根堆
    
    for (int i = 0; i < n; i++) heap.push({a[0] + b[i], 0}); 
    // 0 表示当前 a 的下标 
    
    for (int i = 0; i < n; i++) {
        auto t = heap.top(); 
        heap.pop(); 
        int v = t.first;  // 存储 堆中最小元素的具体和是多少 
        int p = t.second; // 存储 最小元素对应的下标是多少 
        c[i] = v; // 将最小值赋值给 c[i] 共执行 n 次 
        int newValue = v - a[p] + a[p + 1]; 
        int newPosition = p + 1; 
        heap.push({newValue, newPosition}); 
    } 
    
    // 现在 c 中就是存储的 a 和 b 融合的结果 把 c 中的 n 个数字放回 a 中 
    for (int i = 0; i < n; i++) a[i] = c[i]; 
}


int main() {
    int T = 0; 
    cin >> T; 
    
    while (T--) {
        cin >> m >> n; 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        sort(a, a + n);  // 读入第一行数据并进行排序
        
        for (int i = 0; i < m - 1; i++) {
            // 把当前序列和下一个序列进行合并，一共合并 m - 1 次 
            for (int j = 0; j < n; j#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std; 

typedef pair<int, int> PII; 

const int N = 2010; 
int m, n; 
int a[N], b[N], c[N]; 
// a 是第一个序列，已经排序
// b 是要和 a 进行合并的序列 
// c 是一个辅助序列，用于存储 a 和 b 合并的结果 


void merge() {
    function<bool(PII&, PII&)> compare = [](PII& a, PII& b) {
        return a > b; 
    }; 
    priority_queue<PII, vector<PII>, function<bool(PII&, PII&)>> heap(compare); 
    // 小根堆
    
    for (int i = 0; i < n; i++) heap.push({a[0] + b[i], 0}); 
    // 0 表示当前 a 的下标 
    
    for (int i = 0; i < n; i++) {
        auto t = heap.top(); 
        heap.pop(); 
        int v = t.first;  // 存储 堆中最小元素的具体和是多少 
        int p = t.second; // 存储 最小元素对应的下标是多少 
        c[i] = v; // 将最小值赋值给 c[i] 共执行 n 次 
        int newValue = v - a[p] + a[p + 1]; 
        int newPosition = p + 1; 
        heap.push({newValue, newPosition}); 
    } 
    
    // 现在 c 中就是存储的 a 和 b 融合的结果 把 c 中的 n 个数字放回 a 中 
    for (int i = 0; i < n; i++) a[i] = c[i]; 
}


int main() {
    int T = 0; 
    cin >> T; 
    
    while (T--) {
        cin >> m >> n; 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        sort(a, a + n);  // 读入第一行数据并进行排序
        
        for (int i = 0; i < m - 1; i++) {
            // 把当前序列和下一个序列进行合并，一共合并 m - 1 次 
            for (int j = 0; j < n; j++) {
                cin >> b[j]; 
            }
            merge(); 
            // 把 a 和 b 合并，然后把结果存储到 a 中
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' '; 
        }
        cout << endl; 
    }
    
    return 0; 
}++) {
                cin >> b[j]; 
            }
            merge(); 
            // 把 a 和 b 合并，然后把结果存储到 a 中
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' '; 
        }
        cout << endl; 
    }
    
    return 0; 
}
    
    for (int i = 0; i < n; i++) heap.push({a[0] + b[i], 0}); 
    // 0 表示当前 a 的下标 
    
    for (int i = 0; i < n; i++) {
        auto t = heap.top(); 
        heap.pop(); 
        int v = t.first;  // 存储 堆中最小元素的具体和是多少 
        int p = t.second; // 存储 最小元素对应的下标是多少 
        c[i] = v; // 将最小值赋值给 c[i] 共执行 n 次 
        int newValue = v - a[p] + a[p + 1]; 
        int newPosition = p + 1; 
        heap.push({newValue, newPosition}); 
    } 
    
    // 现在 c 中就是存储的 a 和 b 融合的结果 把 c 中的 n 个数字放回 a 中 
    for (int i = 0; i < n; i++) a[i] = c[i]; 
}


int main() {
    int T = 0; 
    cin >> T; 
    
    while (T--) {
        cin >> m >> n; 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        sort(a, a + n);  // 读入第一行数据并进行排序
        
        for (int i = 0; i < m - 1; i++) {
            // 把当前序列和下一个序列进行合并，一共合并 m - 1 次 
            for (int j = 0; j < n; j++) {
                cin >> b[j]; 
            }
            merge(); 
            // 把 a 和 b 合并，然后把结果存储到 a 中
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' '; 
        }
        cout << endl; 
    }
    
    return 0; 
}