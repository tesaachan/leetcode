struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        head->next->next = swapPairs(head->next->next);

        ListNode *tmp = head;
        ListNode *tail = head->next->next;
        head = head->next;
        head->next = tmp;
        head->next->next = tail;

        return head;
    }
};