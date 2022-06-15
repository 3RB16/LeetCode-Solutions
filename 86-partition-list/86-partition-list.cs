/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
  public ListNode Partition(ListNode head, int x) {
        if (head == null)
            return null;
        
        ListNode lessHead = null, lessTail = null;
        ListNode greaterOrEqualHead = null , greaterOrEqualTail = null;
        
        while (head != null) {
            if (head.val < x) {
                if (lessHead == null) {
                    lessHead = head;
                    lessTail = head;
                } else {
                    lessTail.next = head;
                    lessTail = head;
                }
            } else {
                if (greaterOrEqualHead == null) {
                    greaterOrEqualHead = head;
                    greaterOrEqualTail = head;
                } else {
                    greaterOrEqualTail.next = head;
                    greaterOrEqualTail = head;
                }
            }
            head = head.next;
        }
        
        if (lessTail != null)
            lessTail.next = greaterOrEqualHead;
        if (greaterOrEqualTail != null)
            greaterOrEqualTail.next = null;
        
        return lessHead != null ? lessHead : greaterOrEqualHead;
    }
}