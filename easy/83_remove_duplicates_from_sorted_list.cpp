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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val==temp->next->val){
                ListNode* nextnode=temp->next;
                temp->next=nextnode->next;
                nextnode->next=NULL;
                delete nextnode;
            }
            else{
                temp=temp->next;
            }
        }
    return head;
    }
};