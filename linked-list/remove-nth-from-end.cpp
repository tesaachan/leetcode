#include "stdio.h"
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *lenptr = head;
        int len = 0;
        while (lenptr != NULL) {
            lenptr = lenptr->next;
            len++;
        }
        lenptr = head;
        int blen = len - n + 1;
        if (len == 1 && blen == len) {
            lenptr = head;
            head = NULL;
            delete lenptr;
            return head;
        }
        else if (blen == len)
        {
            while (lenptr->next->next != NULL)
                lenptr = lenptr->next;
            delete lenptr->next;
            lenptr->next = NULL;
            return head;
        } 
        else if (blen == 1)
        {
            head = lenptr->next;
            delete lenptr;
            return head;
        } 
        else 
        {
            ListNode *prevptr = head;
            lenptr = lenptr->next;
            while (blen != 2)
            {
                prevptr = prevptr->next;
                lenptr = lenptr->next;
                blen--;
            }
            prevptr->next = lenptr->next;
            delete lenptr;
            return head;
        }
    }
};