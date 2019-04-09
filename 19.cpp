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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) 
            return head;
        int len = getLength(head);
        ListNode dummy(0);
        dummy.next = head;
        ListNode *temp = head;
        ListNode *pre = &dummy;
        for (int i=0;i<len;i++) {
        	if (i==(len-n))
            {
                pre->next = temp->next;
            }
            pre = temp;
            temp = temp->next;
        }
        return dummy.next;
         
    }
private:
    int getLength(ListNode *h) {
        int len = 0;
        while (h) {
            len++;
            h = h->next;
        }
        
        return len;
    }
};
