#include <iostream>
#include <vector>
using namespace std;
int main() {
    //找出所有的偶数，如果不等于总数，输出偶数个数，等于总数输出-1
    //每个偶数加上任意一个奇数还是奇数
    //虽然最终转换后的数组不一样，
    size_t cases = 0;
    cin >> cases;
    size_t endlNumber = cases;
    int temp = 0;
    int evenNumber = 0;

    for (size_t i = 0; i < cases; i++) {
        size_t numSum = 0;
        cin >> numSum;
        vector<int> array;
        for (size_t j = 0; j < numSum; j++) {
            cin >> temp;
            array.push_back(temp);
        }
        for (size_t i = 0; i < array.size(); i++) {
            if (array.at(i) % 2 == 0) {
                evenNumber++;
            }
        }
        if (evenNumber == array.size()) {
            cout << -1;
        } else {
            cout << evenNumber;
        }
        evenNumber = 0;
        //输出指定的回车数量
        if (endlNumber > 1) {
            endlNumber -= 1;
            cout << endl;
        }
    }
    return 0;
}