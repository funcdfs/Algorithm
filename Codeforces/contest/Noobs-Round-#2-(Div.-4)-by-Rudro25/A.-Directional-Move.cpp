#include <iostream>
using namespace std;
int main() {
    //输入一个二进制字符串，输出bob脸的方向
    // 1向左转
    // 0向右转，按照东南西北对应1234倍数，0为+1
    size_t cases = 0;
    cin >> cases;
    //输出指定的回车数量
    size_t endlNumber = cases;
    char direction[] = {'E', 'S', 'W', 'N'};
    //笑死，四个方向写反，根本找不到bug
    int bobFacingIndex = 0;
    for (size_t i = 0; i < cases; i++) {
        string inputString = "";
        size_t stringLength = 0;
        cin >> stringLength >> inputString;
        for (size_t j = 0; j < stringLength; j++) {
            if (inputString.at(j) == '0') {
                bobFacingIndex += 1;
            } else if (inputString.at(j) == '1') {
                bobFacingIndex -= 1;
            }
            bobFacingIndex = bobFacingIndex % 4;
            //因为负数不方便执行一个循环，所以打表了
            if (bobFacingIndex == -3) {
                bobFacingIndex = 1;
            }
            if (bobFacingIndex == -2) {
                bobFacingIndex = 2;
            }
            if (bobFacingIndex == -1) {
                bobFacingIndex = 3;
            }
        }
        if (bobFacingIndex >= 0) {
            cout << direction[bobFacingIndex];
            //必须记得每一个字符串重置，
            bobFacingIndex = 0;
        }
        if (endlNumber > 1) {
            endlNumber -= 1;
            cout << endl;
        }
    }
    return 0;
}