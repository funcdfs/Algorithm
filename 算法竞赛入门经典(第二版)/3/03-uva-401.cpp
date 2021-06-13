#include <iostream>
using namespace std;
/*2021-05-25-21-26*/

string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
// 前26个是字母的镜像，后面的是数字1-9的镜像
string msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string",
                "a mirrored palindrome"};

char r(char ch) {
    if (isalpha(ch)) return rev[ch - 'A'];
    // 判断一个字符是否是一个字母 ctype.h中定义
    // 有 toupper 和 tolower 函数（参数是一个字符）
    return rev[ch - '0' + 25];
}

int main() {
    string s;
    while (cin >> s) {
        int len = s.length();
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - 1 - i]) p = 0;     // 不是回文串
            if (r(s[i]) != s[len - 1 - i]) m = 0;  // 不是镜像串
        }
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
    }
    return 0;
}