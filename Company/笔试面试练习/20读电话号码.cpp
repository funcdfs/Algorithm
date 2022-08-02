// Problem: 读电话号码
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/700/
// date: 2022-07-26 10:46:46
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

string nums[] = {
    "zero", "one", "two",   "three", "four",
    "five", "six", "seven", "eight", "nine",
};

string cnts[] = {"",          "",          "double",   "triple",
                 "quadruple", "quintuple", "sextuple", "septuple",
                 "octuple",   "nonuple",   "decuple"};


void print(string s) {
    // print 将这一段的内容读出来
	for (int i = 0; i < s.size(); i++) {
		int j = i + 1; 
		while (j < s.size() && s[j] == s[i]) {
			j++; 
		} 
		int len = j - i; 
		// 找出这次有几个相同的字符 
		
		if (len >= 2 && len <= 10) {
			cout << cnts[len] << ' ' << nums[s[i] - '0'] << ' '; 
		    // 如果相同的次数在 2 到 10 之间，输出 
		} else if (len > 10) {
			for (int k = 0; k < len; k++) {
				cout << nums[s[i] - '0'] << ' '; 
			}
			// 如果是大于 10 的话，一个一个读一遍
		} else {
			cout << nums[s[i] - '0'] << ' '; 
			// 否则单个数字，单独读一遍不带前缀
		}
		
		i = j - 1; 
		// 然后继续考虑下一个数字段
	}
}

int main() {
    int T = 0;
    cin >> T;

    for (int C = 1; C <= T; C++) {
        string s, seq;
        cin >> s >> seq;

        vector<int> len;
        string str;
        stringstream ssin(seq);

        while (getline(ssin, str, '-')) {
            len.push_back(stoi(str));
        }
        // 将 seq 按照 - 分隔，读入到 len 中

        printf("Case #%d:  ", C);

        int start = 0;
        for (int l : len) {
            print(s.substr(start, l));
            start += l;
        }
        // 然后将原电话号码，分段的传入 print 函数中

        cout << endl;
    }

    return 0;
}