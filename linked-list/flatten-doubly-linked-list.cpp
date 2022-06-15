
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)
            return head;
        Node *ptr = head;
        while (ptr) {
            if (ptr->child) {
                Node *ptr_next = ptr->next;
                ptr->next = flatten(ptr->child);
                ptr->next->prev = ptr;
                ptr->child = nullptr;
                Node *tail = ptr->next;
                while (tail->next)
                    tail = tail->next;
                tail->next = ptr_next;
                if (ptr_next)
                    ptr_next->prev = tail;
            }
            ptr = ptr->next;
        }
        return head;
    }
};