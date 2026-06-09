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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=head->next;
        int count=1;
        while(count<left){
            prev=curr;
            curr=next;
            next=curr->next;
            count++;
        }
        ListNode* prev1=prev;
        // prev->next=prev1;
        ListNode* left1=curr;
        while(count<=right){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(curr){
                next=curr->next;

            }
            // curr->next=prev;
            count++;
        }
        if(prev1){
            prev1->next=prev;
        }else{
            head=prev;
        }
        left1->next=curr;
        return head;
        
    }
};