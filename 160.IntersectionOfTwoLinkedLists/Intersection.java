/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> visit = new HashSet<>();
        ListNode curr = headA;
        while (curr != null) {
            visit.add(curr);
            curr = curr.next;
        }
        curr = headB;
        while (curr != null) {
            if (visit.contains(curr)) {
                return curr;
            }
            curr = curr.next;
        }
        return null;
    }

    public ListNode getIntersectionNode2(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }

        ListNode first = headA, second = headB;
        while (first != second) {
            first = first != null ? first.next : headB;
            second = second != null ? second.next : headA;
        }

        return first;
    }
}
