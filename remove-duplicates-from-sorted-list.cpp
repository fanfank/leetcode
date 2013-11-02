/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return head;
        ListNode *h = head, *p = head, *del = NULL;
        while(p->next != NULL) {
            if(p->next->val == head->val) {
                del = p->next;
                p->next = del->next;
                delete del;
            }
            else {
                head = p->next;
                p = head;
            }
        }
        return h;
    }
};

//used a second level pointer
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return head;
        ListNode **pCur = &head, *del = NULL;
        while((*pCur)->next) {
            if((*pCur)->next->val == (*pCur)->val) {
                del = (*pCur)->next;
                (*pCur)->next = del->next;
                delete del;
            } else {
                pCur = &((*pCur)->next);
            }
        }
        return head;
    }
};
