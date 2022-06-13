struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // NOT FINISHED
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;

        int i = 0;
        while (ptr1 != NULL)
        {
            if (ptr1->val == val) {
                ptr2->next = ptr1->next;
                if (ptr1->next != NULL)
                    ptr1 = ptr1->next;
            }
            ptr1 = ptr1->next;
            if (i % 2)
                ptr2 = ptr2->next;
            i++;
        }
        return head;
    }
};