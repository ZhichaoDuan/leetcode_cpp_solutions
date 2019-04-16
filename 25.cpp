class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummyHead(0);
    dummyHead.next=head;
    ListNode *prev=&dummyHead;
    while(prev!=NULL) {
      prev=reverse(prev,k);
    }
    return dummyHead.next;
  }
private:
  ListNode* reverse(ListNode *prev, int k) {
    ListNode *last=prev;
    for (int i=0;i<k+1;i++) {
      last=last->next;
      if (i!=k&&last==NULL) {
        return NULL;
      }
    }

    ListNode *curr=prev->next->next;
    ListNode *tail=prev->next;
    while(curr!=last) {
      ListNode *next=curr->next;
      curr->next=prev->next;
      tail->next=next;
      prev->next=curr;
      curr=next;
    }
    return tail;
  }
};
