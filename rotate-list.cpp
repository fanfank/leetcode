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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || k == 0)
            return head;
        int sz = 1;
        ListNode *p = head;
        while(p->next) {
            sz++;
            p = p->next;
        }
        k = sz - k % sz;
        p->next = head;
        while(k--)
            p = p->next;
        head = p->next;
        p->next = NULL;
        return head;
    }
};

//same idea but used a second level pointer
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL || k == 0)
            return head;
        ListNode **pCur = &head;
        int sz = 0;
        while(*pCur) {
            pCur = &((*pCur)->next);
            sz++;
        }
        *pCur = head;
        k = (sz - k % sz) % sz;
        while(k--) {
            pCur = &((*pCur)->next);
        }
        head = *pCur;
        *pCur = NULL;
        return head;
    }
};
