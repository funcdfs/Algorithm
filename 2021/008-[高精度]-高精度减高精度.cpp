#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B) {  // 比较两个数字的大小
    if (A.size() != B.size()) return A.size() > B.size();

    for (int i = A.size() - 1; i >= 0; i--) // 注意这里的 i 要倒着遍历
        if (A[i] != B[i]) return A[i] > B[i];

    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) { // 数字的最后一位数字 在 A[0],所以这里从 0 开始遍历
        t = A[i] - t; // 减去之前的借位
        if (i < B.size()) 
            t -= B[i]; // 
        C.push_back((t + 10) % 10);

        if (t < 0) t = 1; // 判断要不要借位
        else t = 0;
        // 小于 0 代表需要借位，不小于 0 代表不需要借位
        // 借位的 可能值只有 0 和 1 
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back(); // 去除前导零 
    return C;
}

// 逆序存储 A B 以及结果 C
int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    vector<int> C;
    
    if (cmp(A, B))
        C = sub(A, B);
    else {
        C = sub(B, A);
        cout << '-';
    }
    for (int i = C.size() - 1; i >= 0; i--) cout << C.at(i);
    return 0;
}

// https:  // www.acwing.com/activity/content/code/content/1403159/