/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *firstNode = headA;
        ListNode *secondNode = headB;
        while(firstNode != secondNode){
            firstNode = firstNode == NULL ? headB : firstNode->next;
            secondNode = secondNode == NULL ? headA : secondNode->next;
        }
        return firstNode;
    }
};