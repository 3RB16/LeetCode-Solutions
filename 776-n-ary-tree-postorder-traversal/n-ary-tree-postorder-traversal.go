/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

func postorder(root *Node) []int {
    order := []int{}
    dfs(root, &order)
    return order
}

func dfs(node *Node, order *[]int) {
    if node == nil {
        return
    }
    for _, child := range node.Children {
        dfs(child, order)
    }
    *order = append(*order, node.Val)
}