/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> order;
        if(!root) return order;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int queue_size = Q.size();
            vector <int> cur_order;
            while(queue_size--) {
                auto cur_node = Q.front();
                Q.pop();
                cur_order.push_back(cur_node->val);
                for(auto child : cur_node->children) {
                    Q.push(child);
                }
            }
            if(!cur_order.empty())
                order.push_back(cur_order);
        }
        return order;
    }
};