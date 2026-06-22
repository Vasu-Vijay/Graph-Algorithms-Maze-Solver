/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        Node dummy(0);
        dummy.next = head;

        Node* new_list = new Node(0);
        Node* nw = new_list;
        for(Node* old = dummy.next; old != NULL; old=old->next) {
            Node* newNode = new Node(0);
            nw->next = newNode;
            nw=nw->next;
            nw->val = old->val;
            mapping.insert({old, nw});
        }
        for(Node *old = dummy.next, *nw = new_list->next; old!=NULL; old=old->next, nw=nw->next) {
            if(old->random) {
                nw->random = mapping[old->random];
            }
        }
        return new_list->next;
    }
};