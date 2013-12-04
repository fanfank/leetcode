/*************************************************************
 Solution 1: Used second level pointer, better than solution 2
 *************************************************************/
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode **pHead = &head, **p = &head, **pp = NULL;
        while(*p) {
            pp = pHead;
            while((*pp)->val <= (*p)->val && pp != p)
                pp = &((*pp)->next);
            if(pp != p) {
                ListNode *tmp = *pp;
                *pp = *p;
                *p = (*p)->next;
                (*pp)->next = tmp;
                continue;
            }
            p = &((*p)->next);
        }
        return *pHead;
    }
};

/*************************************************************
 Solution 2: traditional textbook's method, easy to understand
 *************************************************************/
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *p = head, *pp = NULL;
        while(p && p->next) {
            if(p->next->val < head->val) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                tmp->next = head;
                head = tmp;
                continue;
            }
            pp = head;
            while(pp->next->val <= p->next->val && pp->next != p->next)
                pp = pp->next;
            if(pp->next != p->next) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                tmp->next = pp->next;
                pp->next = tmp;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};