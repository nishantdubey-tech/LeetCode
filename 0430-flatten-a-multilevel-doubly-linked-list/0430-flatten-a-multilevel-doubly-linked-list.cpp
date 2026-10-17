/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return NULL;
        Node *cur=head;
        while(cur!=NULL){
            if(cur->child !=NULL){
                Node *next=cur->next;
                cur->next=flatten(cur->child);
                cur->next->prev=cur;
                cur->child=NULL;
                while(cur->next != NULL){
                    cur=cur->next;
                }
                if(next!=NULL){
                    cur->next=next;
                    next->prev=cur;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};