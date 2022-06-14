struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *tail = reverse(head->next);
        tail->next = head;
        head->next = nullptr;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = head;
        while (new_head && new_head->next)
            new_head = new_head->next;
        reverse(head);
        return new_head;
    }
};