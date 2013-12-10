/****************************************
 Solution 1: a method based on merge sort
 ****************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//a method based on merge sort, I've tried to use quick sort(see blow), but exceeded time limit, maybe it was because it reached the worst case and took up to O(n^2) time
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *p1 = head, *p2 = head, *p3 = NULL;
        while(p2 != NULL && p2->next != NULL) {
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p3->next = NULL;
        p2 = sortList(head);
        p1 = sortList(p1);
        ListNode *list, **pList = &list;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                *pList = p1;
                p1 = p1->next;
            } else {
                *pList = p2;
                p2 = p2->next;
            }
            pList = &((*pList)->next);
        }
        if(p1)
            *pList = p1;
        if(p2)
            *pList = p2;
        return list;
    }
};

/************************************************************************
 Failed Solution 2: a method based on quick sort, yet time limit exceeded
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//a method based on quick sort
public:
    void quickSort(ListNode **pHead, ListNode *end) {
        if(*pHead == end || (*pHead)->next == end)
            return;
        ListNode **pp = &((*pHead)->next), **pMiddle = pHead;
        while(true) {
            while(*pp != end && (*pp)->val >= (*pMiddle)->val)
                pp = &((*pp)->next);
            if(*pp == end)
                break;
            ListNode *node = *pp;
            *pp = node->next;
            node->next = *pHead;
            *pHead = node;
            if(pMiddle == pHead)
                pMiddle = &((*pMiddle)->next);
        }
        quickSort(pHead, *pMiddle);
        quickSort(&((*pMiddle)->next), end);
    }
    ListNode *sortList(ListNode *head) {
        quickSort(&head, NULL);
        return head;
    }
};