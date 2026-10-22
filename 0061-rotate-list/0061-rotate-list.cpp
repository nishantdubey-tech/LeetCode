/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findkthnode(ListNode* head,int k){
        int cnt=1;
        ListNode* temp=head;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len=1;
        ListNode* tail=head;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0)return head;
        k=k%len;
        tail->next=head;
        ListNode* newlastnode=findkthnode(head,len-k);
        head=newlastnode->next;
        newlastnode->next=NULL;
    return head;
    }
};