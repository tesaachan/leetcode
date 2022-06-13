// O(1) space, O(n) time
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reverse(ListNode* cur, ListNode* ptr) {
        ListNode *next = cur->next;
        ListNode *prev = nullptr;
        int i = 0;
        while (cur != nullptr) {
            cur->next = prev;
            prev = cur;
            cur = next;
            if (cur != nullptr)
                next = cur->next;
            i++;
        }
        ptr->next = prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;
        int size = 0;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            size++;
            ptr = ptr->next;
        }
        int i = 0;
        ListNode *ptr1 = head;
        ListNode *ptr2 = head;
        int lsize = (size % 2) ? size / 2 : size / 2 - 1;
        while (i < lsize) {
            ptr2 = ptr2->next;
            i++;
        }
        reverse(ptr2->next, ptr2);
        ptr2 = ptr2->next;
        bool ans = true;
        i = 0;
        while (i < size / 2) {
            if (ptr1->val != ptr2->val) {
                ans = false;
                break;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            i++;
        }
        return ans;
    }
};
