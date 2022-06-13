// https://russianblogs.com/article/4180107894/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fastptr = head;
        ListNode *slowptr = head;
        int i = 0;
        while (fastptr != NULL)
        {
            fastptr = fastptr->next;
            if (i % 2)
                slowptr = slowptr->next;
            if (fastptr == slowptr && i % 2)
            {
                ListNode *slowptr2 = head;
                int j = 0;
                while (slowptr2 != slowptr)
                {
                    slowptr2 = slowptr2->next;
                    slowptr = slowptr->next;
                }
                return slowptr2;
            }
            i++;
        }
        return NULL;
    }
};