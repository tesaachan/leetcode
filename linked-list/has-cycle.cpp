/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fastptr = head;
        ListNode *slowptr = head;
        int i = 0;
        while (fastptr != NULL)
        {
            fastptr = fastptr->next;
            if (i % 2)
                slowptr = slowptr->next;
            i++;
            if (fastptr == slowptr) {
                return true;
            }
        }
        return false;
    }
};