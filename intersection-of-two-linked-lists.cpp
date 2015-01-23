/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//============================
//Solution 1: my ugly solution
//============================
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


//==========================================
//Solution 2: best solution. please refer to 
//      https://oj.leetcode.com/discuss/17278/accepted-shortest-explaining-algorithm-comments-improvements
//==========================================
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }

    return p1;
}
