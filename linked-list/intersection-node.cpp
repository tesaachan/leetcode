struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA->next != NULL) {
            ptrA = ptrA->next;
            lenA++;
        }
        while (ptrB->next != NULL) {
            ptrB = ptrB->next;
            lenB++;
        }
        ptrA = headA;
        ptrB = headB;
        int diff = abs(lenA - lenB);
        if (lenA > lenB) {
            while (diff != 0) {
                ptrA = ptrA->next;
                diff--;
            }
        } else {
            while (diff != 0) {
                ptrB = ptrB->next;
                diff--;
            }
        }
        while (ptrA != ptrB) {
            ptrA = ptrA->next;
            ptrB = ptrB->next; 
        }
        return ptrA;
    }
};
