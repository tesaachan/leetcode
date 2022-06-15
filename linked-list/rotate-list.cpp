struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        int size = 0;
        ListNode *len = head;
        ListNode *ptr = nullptr;
        while (len) {
            ptr = len;
            len = len->next;
            size++;
        }
        k = k % size;
        k = size - k;
        ptr->next = head;
        for (int i = 0; i < k; i++) {
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = nullptr;
        return head;
    }
};