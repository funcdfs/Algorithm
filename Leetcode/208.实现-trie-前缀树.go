/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode.cn/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (71.87%)
 * Likes:    1028
 * Dislikes: 0
 * Total Accepted:    165.2K
 * Total Submissions: 229.8K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Trie（发音类似 "try"）或者说 前缀树
 * 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。
 * 
 * 请你实现 Trie 类：
 * 
 * 
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回
 * false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true
 * ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 * 
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
 * 
 * 
 */

 package leetcode
 
 /* --- 2022-01-20-21-12 --- */
 
 // https://github.com/fengwei2002/Algorithm
 
 // solution link: 
 // https://leetcode.cn/problems/implement-trie-prefix-tree/solution/lc208-fengwei2002-by-kycu-jiww/
 

// @lc code=start
type Trie struct {
    ne [26]*Trie
    end bool
}

func newTrie() *Trie {
    t := new(Trie)
    for i := 0; i <     26; i++ {
        t.ne[i] = nil
    }
    t.end = false
    return t
}

func Constructor() Trie {
    return *newTrie()
}


func (this *Trie) Insert(word string)  {
    p := this
    for _, c := range word {
        u := c - 'a'
        if p.ne[u] == nil {
            p.ne[u] = newTrie()
        }
        p = p.ne[u]
    }
    p.end = true
}


func (this *Trie) Search(word string) bool {
    p := this
    for _, c := range word {
        u := c - 'a'
        if p.ne[u] == nil {
            return false
        }
        p = p.ne[u]
    }
    return p.end
}


func (this *Trie) StartsWith(prefix string) bool {
    p := this
    for _, c := range prefix {
        u := c - 'a'
        if p.ne[u] == nil { 
            return false
        }
        p = p.ne[u]
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end

