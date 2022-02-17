/*
 * @lc app=leetcode.cn id=133 lang=golang
 * [133] 克隆图
 */

package leetcode

/* --- 2022-02-15-09-20 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
//https://leetcode-cn.com/problems/clone-graph/solution/lc133-fengwei2002-by-konng0120-wz7y/
type Node struct {
	Val       int
	Neighbors []*Node
}

// @lc code=start
func cloneGraph(node *Node) *Node {
	hash := make(map[int]*Node, 100)
	// 因为存在重边，相比遍历树要加上用来判重的哈希表

	// 对每个具体的数字用哈希表存储一个 node
	return dfs(node, hash)
}

func dfs(node *Node, hash map[int]*Node) *Node {
	if node == nil {
		return nil
	}
	// 传入一个节点和一个哈希表
	if n, ok := hash[node.Val]; ok == true {
		return n // 如果这个值之前出现过，直接返回这个值对应的 node
	}

	cNode := &Node{
		Val: node.Val,
	} // 创建一个新的 node

	hash[node.Val] = cNode
	// 哈希表中将这个值插入，对应的值为新的 node

	for _, neighbor := range node.Neighbors {
		// 遍历当前 node 的所有出边
		// 同时进行点和点之间的连线
		cNode.Neighbors = append(cNode.Neighbors, dfs(neighbor, hash))
	}

	return cNode
}

// @lc code=end
