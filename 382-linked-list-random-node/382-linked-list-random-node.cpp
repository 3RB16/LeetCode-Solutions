class Solution {
public:
    vector<int> nodes;
    Solution(ListNode* head) {
        while (head != NULL) {
            nodes.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int index = rand() % (int)nodes.size();
        return nodes[index];
    }
};
