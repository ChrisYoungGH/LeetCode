/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        int length = 0;
        ListNode curr = head;
        while (curr != null) {
            curr = curr.next;
            length++;
        }

        int count = 0;
        ListNode right = head;
        while (count < length / 2) {
            right = right.next;
            count++;
        }

        if (length % 2 != 0) {
            right = right.next;
        }

        count = 0;
        ListNode left = null;
        while (count < length / 2) {
            curr = head;
            head = head.next;
            curr.next = left;
            left = curr;
            count++;
        }

        while (left != null && right != null) {
            if (left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }

        return true;
    }
}
