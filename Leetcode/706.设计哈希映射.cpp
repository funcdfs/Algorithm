/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*2021-07-21-19-04*/
// ? 思路解析：
/*
 *
 * yxc蹲坑法创建哈希表
 *
 *
 ! --难点： c++类成员函数的语法？
 ! --
 ! --
 */
// @lc code=start
class MyHashMap {
   public:
    MyHashMap() { hashTable = vector<pair<int, int>>(N, {-1, -1}); }

    int find(int key) {
        int k = key % N;
        while (hashTable[k].first != key && hashTable[k].first != -1) {
            k = (k + 1) % N;
        }

        return k;
    }

    void put(int key, int value) {
        auto k = find(key);
        hashTable[k] = {key, value};
    }

    int get(int key) {
        auto k = find(key);
        if (hashTable[k].first == -1) {
            return -1;
        }

        return hashTable[k].second;
    }

    void remove(int key) {
        auto k = find(key);
        if (hashTable[k].first != -1) {
            hashTable[k].first =
                -2;  // Mark as deleted (use a different value with -1)
        }
    }

   private:
    const static int N = 20011;
    vector<pair<int, int>> hashTable;
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
