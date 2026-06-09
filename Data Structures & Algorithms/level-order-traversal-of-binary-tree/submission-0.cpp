/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        else{
            return {};
        }
        q.push(NULL);
        while(!q.empty()){
            vector<int> curr;
            while(!q.empty() &&q.front()!=NULL){
                auto it=q.front();
                curr.push_back(it->val);
                q.pop();
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
            ans.push_back(curr);
            q.pop();
            if(!q.empty()) q.push(NULL);
        }
        return ans;
    }
};
