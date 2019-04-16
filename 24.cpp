#include <bits/stdc++.h>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

      ListNode dummyNode(0);
      dummyNode.next=head;
      ListNode *pre = &dummyNode;

      while (pre->next&&pre->next->next) {
        ListNode *final = pre->next->next->next;
        ListNode *first = pre->next;
        pre->next = pre->next->next;
        pre->next->next = first;
        pre->next->next->next=final;
        pre = pre->next->next;

      }

      return dummyNode.next;
};
