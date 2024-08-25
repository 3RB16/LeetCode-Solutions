/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func postorderTraversal(root *TreeNode) []int {
    var nodesOrder []int
    postorder(root, &nodesOrder)
    return nodesOrder
}

func postorder(root *TreeNode, nodesOrder *[]int) {
    if root == nil {
        return
    }
    postorder(root.Left, nodesOrder)
    postorder(root.Right, nodesOrder)
    *nodesOrder = append(*nodesOrder, root.Val)
}
