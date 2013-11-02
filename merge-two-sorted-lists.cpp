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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //create a dummy head
        ListNode *dh = new ListNode(0), *tmp = dh;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            }
            else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        if(l1 != NULL)
            tmp->next = l1;
        if(l2 != NULL)
            tmp->next = l2;
        
        tmp = dh;
        dh = dh->next;
        delete tmp;
        
        return dh;
    }
};

//use a second level pointer
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = NULL;
        ListNode **ppHead = &head;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val < l2->val) {
                *ppHead = l1;
                l1 = l1->next;
            }
            else {
                *ppHead = l2;
                l2 = l2->next;
            }
            ppHead = &((*ppHead)->next);
        }
        *ppHead = l1==NULL?l2:l1;
        return head;
    }
};
