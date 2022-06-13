// https://www.programcreek.com/2014/05/leetcode-reverse-linked-list-java/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *reversed = NULL;
        for (ListNode *ptr = head; ptr != NULL; ptr = ptr->next) {
            reversed = new ListNode(ptr->val, reversed);
        }
        head = reversed;
        return head;
    }
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* ptr1 = head;
    //     ListNode* ptr2 = head->next;

    //     while (ptr1 != NULL && ptr2 != NULL)
    //     {
    //         ListNode* tmp = ptr2->next;
    //         ptr2->next = ptr1;
    //         ptr1 = ptr2;
    //         ptr2 = tmp;
    //     }
    //     return ptr1;
    // }
};