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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //create a dummy head
        ListNode *dh = new ListNode(0), *p = dh, *tmp = NULL;
        dh->next = head;
        head = dh;
        while(head->next) {
            if(head->next->val < x) {
                if(head->next == p->next) {
                    p = head = head->next;
                    continue;
                }
                tmp = head->next;
                head->next = tmp->next;
                tmp->next = p->next;
                p->next = tmp;
                p = tmp;
            }
            else
                head = head->next;
        }
        
        head = dh->next;
        delete dh;
        return head;
    }
};

//used second level pointers
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode **pInsert = &head, **pCur = &head;
        while(*pCur) {
            if((*pCur)->val < x) {
                if(pCur == pInsert) {
                    pCur = pInsert = &((*pCur)->next);
                    continue;
                }
                ListNode *tmp = *pCur; //save address
                *pCur = (*pCur)->next; //cover current node
                tmp->next = *pInsert;  
                *pInsert = tmp;
                pInsert = &(tmp->next);
            } else {
                pCur = &((*pCur)->next);
            }
        }
        return head;
    }
};
