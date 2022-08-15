#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int P = 0; 
    cin >> P; 
    
    while (P--) {
        int id = 0; 
        cin >> id; 
        int M = 0; 
        cin >> M;
        cout << id << " " << (M + 1) / 2 << endl; 
        
        function<bool(int&, int&)> maxEleCom = [](int& a, int& b) {
            return a < b; 
        }; 
        function<bool(int&, int&)> minEleCom = [](int& a, int& b) {
            return a > b; 
        }; 
        
        priority_queue<int, vector<int>, function<bool(int&, int&)>> maxPQ(maxEleCom); 
        // 从小到大 左边是一个大根堆，存储所有的小于等于 x 的元素 
        
        priority_queue<int, vector<int>, function<bool(int&, int&)>> minPQ(minEleCom); 
        // 从大到小 右边是一个小根堆，存储所有的大于等于 x 的元素
        
        int cnt = 0; 
        for (int i = 0; i < M; i++) {
            int x = 0;
            cin >> x;

            if (maxPQ.empty() || x <= maxPQ.top()) maxPQ.push(x); 
            else minPQ.push(x); 
            
            // 如果堆中的元素数量相差大于 1，将多余的那一个进行调整 
            if (maxPQ.size() > minPQ.size() + 1) {
                minPQ.push(maxPQ.top()); 
                maxPQ.pop(); 
            }
            if (minPQ.size() > maxPQ.size()) {
                maxPQ.push(minPQ.top()); 
                minPQ.pop(); 
            } // 人为规定左边的 maxHeap 多一个 node 
            
            if ((i + 1) % 2 != 0) { // 当输入的个数为奇数的时候，输出左边的堆顶元素
                cout << maxPQ.top() << " "; 
                if (++cnt % 10 == 0) cout << endl; 
            }
        }
        
        if (cnt % 10) cout << endl; 
    }
    
    return 0;    
}


