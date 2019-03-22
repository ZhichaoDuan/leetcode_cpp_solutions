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
        std::set<ListNode*> ns;
        while(headA) {
            ns.insert(headA);
            headA = headA->next;
        }
        
        while(headB) {
            if (ns.find(headB) != ns.end()) {
                return headB;
            }
            headB = headB->next;
        }
        
        return NULL;
    }
};
