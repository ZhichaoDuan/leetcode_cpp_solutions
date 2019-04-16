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
    int t = n-m+1;
    ListNode dummHead(0);
    dummHead.next=head;
    head=&dummHead;
    ListNode *pre_head=&dummHead;
    while(m--) {
      pre_head=head;
      head=head->next;
    }

    ListNode *modified_tail=head;
    ListNode *new_head=NULL;
    while(t--) {
      ListNode *next = head->next;
      head->next = new_head;
      new_head = head;
      head=next;
    }

    modified_tail->next=head;
    pre_head->next=new_head;
    return dummHead.next;
  }
};
