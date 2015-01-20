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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) {
            return headA;
        } else if (headA == NULL || headB == NULL) {
            return NULL;
        }   

        ListNode *tailA = headA;
        while (tailA->next != NULL) {
            tailA = tailA->next;
        }   
        tailA->next = headA;

        ListNode *fast_pointer = headB;
        ListNode *slow_pointer = headB;
        ListNode *intersect_pointer = NULL;
        do {
            fast_pointer = move(fast_pointer, 2); 
            if (fast_pointer == NULL) {
                break;
            }   

            slow_pointer = move(slow_pointer, 1); 
        } while (fast_pointer != slow_pointer);                                                                                                                                                                                              

        if (fast_pointer != NULL) {
            intersect_pointer = headB;
            while (intersect_pointer != slow_pointer) {
                intersect_pointer = move(intersect_pointer, 1); 
                slow_pointer      = move(slow_pointer, 1); 
            }   
        }   
        
        tailA->next = NULL;
        return intersect_pointer;
    }   

    ListNode *move(ListNode *pointer, int step) {
        while (step--) {
            if (pointer == NULL) {
                return NULL;
            }   
            pointer = pointer->next;
        }   
        return pointer;
    }   
};
