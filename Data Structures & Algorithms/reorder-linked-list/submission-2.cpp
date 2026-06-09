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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* next;
        ListNode* prev=NULL;
        while(temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode* temp1=reverse(slow);
        ListNode* temp=head;
        while(temp && temp1){
            ListNode* next=temp->next;
            ListNode* next1=temp1->next;
            temp->next=temp1;
            if(next!=NULL){
                temp1->next=next;

            }
            temp1=next1;
            temp=next;
        }
        
        // return head;

    }
};
