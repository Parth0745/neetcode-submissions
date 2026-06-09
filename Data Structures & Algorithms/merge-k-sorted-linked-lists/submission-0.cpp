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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto &it:lists){
            if(it){
                pq.push({it->val,it});
            }
        }
        ListNode* dummy=new ListNode();
        ListNode* head1=dummy;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            dummy->next=it.second;
            dummy=dummy->next;
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }
        }
        return head1->next;
    }
};
