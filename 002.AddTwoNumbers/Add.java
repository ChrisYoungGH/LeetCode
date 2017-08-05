
// Definition for singly-linked list.

public class Add {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode curr = head;
        int carry = 0;

        while (l1 != null || l2 != null || carry != 0) {
            int v1 = 0, v2 = 0;
            if (l1 != null) {
                v1 = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                v2 = l2.val;
                l2 = l2.next;
            }

            int sum = v1 + v2 + carry;
            int val = sum % 10;
            carry = sum / 10;

            curr.next = new ListNode(val);
            curr = curr.next;
        }

        return head.next;
    }

    public static void main(String[] args) {
        ListNode l1 = ListNode.createList(new int[]{9,9,9});
        ListNode l2 = ListNode.createList(new int[]{2,2});
        ListNode l = new Add().addTwoNumbers(l1, l2);

        ListNode.printList(l1);
        ListNode.printList(l2);
        ListNode.printList(l);
    }
}


class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }

    public static void printList(ListNode list) {
        while (list != null) {
            System.out.print(list.val);
            list = list.next;
        }
        System.out.println();
    }

    public static ListNode createList(int[] list) {
        ListNode head = new ListNode(0);
        ListNode curr = head;
        for (int i = 0; i < list.length; i++) {
            curr.next = new ListNode(list[i]);
            curr = curr.next;
        }
        return head.next;
    }
}
