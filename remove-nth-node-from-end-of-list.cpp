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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n == 0)
            return head;
            
        //creat a dummy head, remember to assign dummy's next
        ListNode *dh = new ListNode(0);
        dh ->next = head;
        ListNode *del = NULL, *p = dh;
        
        queue<ListNode*> q;
        while(p != NULL) {
            if(q.size() > n)
                q.pop();
            q.push(p);
            p = p->next;
        }
        
        //get the n+1th one
        p = q.front();
        
        //delete the nth one
        del = p->next;
        p->next = del->next;
        delete del;
        
        del = dh;
        dh = dh->next;
        delete del;
        
        return dh; //always remember to return
    }
};

//used a second level pointer
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode **pFast = &head, **pSlow = &head;
        while(--n) {
            pFast = &((*pFast)->next);
        }
        while((*pFast)->next) {
            pFast = &((*pFast)->next);
            pSlow = &((*pSlow)->next);
        }
        *pSlow = (*pSlow)->next;
        return head;
    }
};
