/*
 * @lc app=leetcode.cn id=173 lang=golang
 *
 * [173] 二叉搜索树迭代器
 */
package leetcode

/* --- 2022-02-17-16-15 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/binary-search-tree-iterator/solution/lc173-fengwei2002-by-konng0120-4c8e/

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// @lc code=start
type BSTIterator struct {
	stack []*TreeNode
	cur   *TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	return BSTIterator{cur: root}
}

func (this *BSTIterator) Next() int {

	for node := this.cur; node != nil; node = node.Left {
		this.stack = append(this.stack, node)
	} // 将 cur 的左链全部放入

	this.cur, this.stack = this.stack[len(this.stack)-1], this.stack[:len(this.stack)-1]
	// 弹出栈顶元素

	val := this.cur.Val
	// 返回栈顶元素的值

	this.cur = this.cur.Right
	// 更新 cur 为右侧链表

	return val
}

func (this *BSTIterator) HasNext() bool {
	// 如果 cur 不为空或者 stk 中存在节点， 那么就说明仍然存在下一个节点
	return this.cur != nil || len(this.stack) > 0
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
// @lc code=end
