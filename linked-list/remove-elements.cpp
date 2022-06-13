struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *removed = new ListNode(0);
        ListNode *start = removed;
        for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->val != val)
            {
                if (removed == NULL)
                    removed = new ListNode(ptr->val);
                else
                    removed->next = new ListNode(ptr->val);
                removed = removed->next;
            }
        }
        return start->next;
    }
};