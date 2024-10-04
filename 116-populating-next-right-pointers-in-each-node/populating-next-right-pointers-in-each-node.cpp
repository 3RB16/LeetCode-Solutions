/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (! root) {
            return root;
        }
        queue <Node*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int queue_size = Q.size();
            for(int node = 0;node < queue_size;node++){
                Node* cur_node = Q.front();
                Q.pop();

                if (node != queue_size - 1) {
                    Node* next_node = Q.front();
                    cur_node->next = next_node;
                }

                if(cur_node->left) {
                    Q.push(cur_node->left);
                }
                if(cur_node->right) {
                    Q.push(cur_node->right);
                }
            }
        }
        return root;
    }
};