/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node *, int> node_map;
        std::vector<Node *> node_vec;
        Node *ptr=head;
        int i=0;
        while(ptr) {
            Node *tmp = new Node();
            tmp->val = ptr->val;
            tmp->next = NULL;
            tmp->random = NULL;
            node_vec.push_back(tmp);
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        node_vec.push_back(NULL);
        ptr = head;
        i = 0;
        while(ptr) {
            node_vec[i]->next = node_vec[i+1];
            if (ptr->random) {
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};