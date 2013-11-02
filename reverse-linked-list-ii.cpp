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
    void reverseAndSet(ListNode *p1, ListNode *p2) {
        ListNode *pre = NULL, *cur = p1, *next = NULL;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        next = p2->next;
        p2->next = pre;
        p1->next = next;
    }
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //create dummy head
        ListNode *dh = new ListNode(0);
        dh->next = head;
        n = n-m;
        
        //split
        ListNode *pHead1 = dh, *pHead2 = NULL, *pTail2 = NULL;
        while(--m) {
            pHead1 = pHead1->next;
        }
        pTail2 = pHead2 = pHead1->next;
        n = n - m;
        while(n--) {
            pTail2 = pTail2->next;
        }
        
        pHead1->next = pTail2->next;
        pTail2->next = NULL;
        
        //merge
        reverseAndSet(pHead2, pHead1);
        
        pHead1 = dh->next;
        delete dh;
        return pHead1;
    }
};
//wrong1: forget line 28

//Used second level pointer
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sz = n - m + 1;
        ListNode **ppHead = &head;
        while(--m) {
            ppHead = &((*ppHead)->next);
        }
        ListNode *pre = NULL, *cur = *ppHead, *next = NULL;
        while(sz--) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        (*ppHead)->next = cur;
        *ppHead = pre;
        return head;
    }
};
