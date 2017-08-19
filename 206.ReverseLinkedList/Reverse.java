/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode newHead = null, curr = head;
        while (curr != null) {
            ListNode prev = curr;
            curr = curr.next;
            prev.next = newHead;
            newHead = prev;
        }

        return newHead;
    }
}
