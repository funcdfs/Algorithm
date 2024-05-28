#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int bfs(string state) {
    queue<string> queueString;
    unordered_map<string, int> stepCount;

    queueString.push(state);
    stepCount[state] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    string endString = "12345678x";
    while (queueString.size()) {
        auto temp = queueString.front();
        queueString.pop();

        if (temp == endString) return stepCount[temp];

        int distance = stepCount[temp];
        int xIndex = temp.find('x');
        int x = xIndex / 3, y = xIndex % 3;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3) {
                swap(temp[a * 3 + b], temp[xIndex]);

                if (stepCount.count(temp) == 0) {
                    stepCount[temp] = distance + 1;
                    queueString.push(temp);
                }

                swap(temp[a * 3 + b], temp[xIndex]);
                // 因为上下左右都要用 temp 计算一次是否符合，所以还需要换回去
            }
        }
    }

    return -1;
}

int main() {
    char s[2];

    string state;
    for (int i = 0; i < 9; i++) {
        cin >> s;
        state += *s;
    }

    cout << bfs(state) << endl;

    return 0;
}
// https://www.acwing.com/activity/content/code/content/1521289/