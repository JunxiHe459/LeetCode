/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

  public ListNode oddEvenList(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode odd_curr = head;
    ListNode even_head = head.next;
    ListNode even_curr = even_head;
    ListNode temp = head.next.next;

    int i = 1;
    while (temp != null) {
      if (i % 2 == 1) {
        odd_curr.next = temp;
        odd_curr = odd_curr.next;
      } else {
        even_curr.next = temp;
        even_curr = even_curr.next;
      }
      temp = temp.next;
      i += 1;
    }

    odd_curr.next = even_head;
    even_curr.next = null;
    return head;
  }

  // Same idea but a smarter one
  public ListNode oddEvenList(ListNode head) {
    if (head == null || head.next == null) {
      return head;
    }

    ListNode odd_curr = head;
    ListNode even_head = head.next;
    ListNode even_curr = even_head;

    while (even_curr != null && even_curr.next != null) {
      odd_curr.next = odd_curr.next.next;
      odd_curr = odd_curr.next;

      even_curr.next = even_curr.next.next;
      even_curr = even_curr.next;
    }

    odd_curr.next = even_head;
    return head;
  }
}
