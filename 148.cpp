#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*1->5->4->3*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head||!head->next) {
            return head;
        }
        ListNode* mid;
        mid = getMiddle(head);
        head = sortList(head);
        mid = sortList(mid);
        head = mergeSortedList(head, mid);
        return head;
    }

    ListNode* mergeSortedList(ListNode* n1, ListNode* n2) {
        ListNode dummyHead(0);
        ListNode *head = &dummyHead;
        while(n1&&n2) {
            if (n1->val<n2->val) {
                head->next = n1;
                n1=n1->next;
            } else {
                head->next = n2;
                n2=n2->next;
            }
            head = head->next;
        }
        if (n1!=NULL) {
            head->next = n1;
        }
        if (n2!=NULL) {
            head->next = n2;
        }
        return dummyHead.next;
    }

    ListNode* getMiddle(ListNode* head) {
        ListNode *fast, *slow;
        fast = head;
        slow = head;
        while(fast->next&&fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }


};
