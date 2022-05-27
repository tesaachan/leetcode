/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */

object Solution {
    def removeNthFromEnd(head: ListNode, n: Int): ListNode = {
        var len = 0
        var ref = head
        while (ref != null) {
            ref = ref.next
            len += 1
        }
        if (len == n) {
            return head.next
        }
        ref = head
        for (i <- 0 until (len - n - 1)) {
            ref = ref.next
        }
        var rest = ref.next.next
        ref.next = rest
        head
    }
}