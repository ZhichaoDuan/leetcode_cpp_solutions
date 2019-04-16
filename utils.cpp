#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *vecToList(std::vector<int>& v) {
  ListNode head(0);
  ListNode *ptr=&head;
  for(int val:v) {
    ListNode *tmp = new ListNode(val);
    ptr->next=tmp;
    ptr=ptr->next;
  }

  return head.next;
}

void showList(ListNode *l) {
  while(l) {
    cout<<l->val;
    if (l->next) {
      cout<<"->";
    }
    l=l->next;
  }
}
