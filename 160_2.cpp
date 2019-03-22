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
    int getLen(ListNode *ln) {
        int len = 0;
        while(ln) {
            len++;
            ln = ln->next;
        }
        return len;
    }
    
    ListNode *adjust(ListNode *ln, int len) {
        while(ln&&len) {
            len--;
            ln=ln->next;
        }
        
        return ln;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        if (lenA>lenB){
            headA=adjust(headA, lenA-lenB);
        } else {
            headB=adjust(headB, lenB-lenA);
        }
        
        while(headA&&headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
