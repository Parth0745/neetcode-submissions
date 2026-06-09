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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(0);
        ListNode* ans=dummy;
        int carry=0;
        while(l1||l2){
            int val=0;
            if(l1){
                val+=(l1->val);
                l1=l1->next;
            }
            if(l2){
                val+=(l2->val);
                l2=l2->next;
            }
            int sum=val+carry;
            val=sum%10;
            carry=sum/10;
            dummy->next=new ListNode(val);
            dummy=dummy->next;
        }
        if(carry) dummy->next=new ListNode(carry);
        return ans->next;;
    }
};
