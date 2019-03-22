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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int len = n-m+1;
        
        ListNode* pre_head = NULL;
        ListNode* res = head;
        while (head&&--m) {
            pre_head = head;
            head = head->next;
        }
        ListNode* modified_tail = head;
        ListNode* new_head=NULL;
        while(head&&len) {
            ListNode* next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            len--;
        }
        modified_tail->next = head;
        if (pre_head){
            pre_head->next = new_head;
        }
        else{
            res = new_head;
        }
        return res;
    }
};
