struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *tail = head->next;
        ListNode *o0 = head;
        ListNode *o1 = head->next;
        if (head->next != nullptr) {
            ListNode *oi = head->next->next;
            int i = 0;
            while (oi != nullptr) {
                if (i % 2 == 0) {
                    o0->next = oi;
                    o0 = o0->next;
                } else {
                    o1->next = oi;
                    o1 = o1->next;
                }
                oi = oi->next;
                i++;
            }
            o0->next = nullptr;
            o1->next = nullptr;
            o0->next = tail;
        }
        return head;
    }
};
