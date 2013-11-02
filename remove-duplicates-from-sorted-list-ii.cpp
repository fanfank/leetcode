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
    bool judgeDuplication(ListNode *cur) {
        if(cur->next == NULL)
            return false;
        return (cur->val == cur->next->val);
    }
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //create a dummy head
        ListNode *dh = new ListNode(0);
        dh->next = head;
        ListNode *p = dh, *del = NULL;
        
        //judge duplications and delete
        while(p->next != NULL) {
            if(judgeDuplication(p->next)) {
                int last = p->next->val;
                while(p->next != NULL && p->next->val == last) {
                    del = p->next;
                    p->next = del->next;
                    delete del;
                }
            }
            else {
                p = p->next;
            }
        }
        
        del = dh;
        dh = dh->next;
        delete del;
        return dh;
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
        int last;
        while((*pCur) != NULL && (*pCur)->next != NULL) {
            if((*pCur)->next->val == (*pCur)->val) {
                last = (*pCur)->val;
                while((*pCur) != NULL && (*pCur)->val == last) {
                    del = *pCur;
                    *pCur = del->next;
                    delete del;
                }
            } else {
                pCur = &((*pCur)->next);
            }
        }
        return head;
    }
};
