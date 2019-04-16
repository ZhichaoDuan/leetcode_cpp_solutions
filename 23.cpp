class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size()==0) return NULL;
    if (lists.size()==1) {
      return lists[0];
    }
    if (lists.size()==2) {
      return mergeOnce(lists[0], lists[1]);
    }

    std::vector<ListNode*> v1;
    std::vector<ListNode*> v2;
    int mid=lists.size()/2;
    for (size_t i = 0; i < mid; i++) {
      v1.push_back(lists[i]);
    }
    for (size_t i = mid; i < lists.size(); i++) {
      v2.push_back(lists[i]);
    }

    ListNode *l1=mergeKLists(v1);
    ListNode *l2=mergeKLists(v2);
    return mergeOnce(l1,l2);
  }
private:
  ListNode* mergeOnce(ListNode* a, ListNode* b) {
    ListNode dummyHead(0);
    ListNode* res = &dummyHead;
    while(a&&b) {
      if (a->val>=b->val) {
        res->next=new ListNode(b->val);
        res=res->next;
        b=b->next;
      }
      else {
        res->next=new ListNode(a->val);
        res=res->next;
        a=a->next;
      }
    }

    while (a) {
      res->next=new ListNode(a->val);
      res=res->next;
      a=a->next;
    }

    while (b) {
      res->next=new ListNode(b->val);
      res=res->next;
      b=b->next;
    }

    return dummyHead.next;
  }
};
