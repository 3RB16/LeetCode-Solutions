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
    if len(node.Children) > 0 {
        for _, c := range node.Children {
            dfs(c, order)
        }
    }
    *order = append(*order, node.Val)
}