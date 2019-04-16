#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
      ListNode *fast=head;
      ListNode *slow=head;
      ListNode *meet=NULL;
      while (fast) {
        fast=fast->next;
        slow=slow->next;
        if (!fast) {
          return NULL;
        }
        fast=fast->next;
        if (fast==slow) {
          meet=slow;
          break;
        }
      }

      return bool(meet);

    }
};
