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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* temp=head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        if(count-n==0) return head->next;
        int a=1;
        temp=head;
        while(temp && a<count-n){
            temp=temp->next;
            a++;
        }
        temp->next=temp->next->next;
        return head;

    }
};
