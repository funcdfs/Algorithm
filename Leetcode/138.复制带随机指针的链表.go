/*
 * @lc app=leetcode.cn id=138 lang=golang
 *
 * [138] 复制带随机指针的链表
 */
package leetcode

/* --- 2022-02-16-11-24 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/lc136-fengwei2002-by-konng0120-488t/

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

// @lc code=start

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	cur := head
	hash := make(map[*Node]*Node)

	for cur != nil {
		hash[cur] = &Node{
			Val: cur.Val,
		}
		cur = cur.Next
	}

	cur = head

	for cur != nil {
		hash[cur].Next = hash[cur.Next]
		hash[cur].Random = hash[cur.Random]
		cur = cur.Next
	}

	return hash[head]
}

// @lc code=end
