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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == NULL)
            return NULL;
        ListNode **pCur = &head, *next = NULL;
        while(*pCur && (*pCur)->next) {
            next = (*pCur)->next;
            (*pCur)->next = next->next;
            next->next = *pCur;
            *pCur = next;
            pCur = &((*pCur)->next->next);
        }
        return head;
    }
};