/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        RandomListNode *p = head, *np = NULL, *newHead = NULL;
        while(p) {
            RandomListNode *newNode = new RandomListNode(p->label);
            newNode->next = p->next;
            p->next = newNode;
            p = newNode->next;
        }
        p = head;
        while(p) {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        p = head;
        if(p) {
            newHead = np = p->next;
            p->next = p->next->next;
            p = p->next;
        }
        while(p) {
            np->next = p->next;
            np = np->next;
            p->next = p->next->next;
            p = p->next;
        }
        return newHead;
    }
};