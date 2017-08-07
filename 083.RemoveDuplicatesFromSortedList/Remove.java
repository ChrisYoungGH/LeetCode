// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}


public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode prev = head, curr = head.next;
        while (curr != null) {
            if (curr.val != prev.val) {
                prev.next = curr;
                prev = prev.next;
            }
            curr = curr.next;
        }
        prev.next = null;

        return head;
    }
}
