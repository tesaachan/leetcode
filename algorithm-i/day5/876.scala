/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */

object Solution {
    def middleNode(head: ListNode): ListNode = {
        var len = 0
        var ref = head
        while (ref != null) {
            ref = ref.next
            len += 1
        }
        ref = head
        for (i <- 0 until len/2) {
            ref = ref.next
        }
        ref
    }
}