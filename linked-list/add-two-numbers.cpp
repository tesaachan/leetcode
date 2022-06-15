struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *new_list = nullptr;
        ListNode *ll = new_list;
        int current;
        int next = 0;
        while (l1 || l2) {
            int sum;
            if (l2 && l1)
                sum = l1->val + l2->val;
            else if (l1) sum = l1->val;
            else sum = l2->val;

            current = (next + sum) % 10;
            next = sum / 10;

            if (!new_list) {
                ll = new ListNode(current);
                new_list = ll;
            }
            else {
                ll->next = new ListNode(current);
                ll = ll->next;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (next != 0)
            ll->next = new ListNode(next);
        return new_list;
    }
};