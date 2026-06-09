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
    int maxSum=INT_MIN;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftSum=helper(root->left);
        int rightSum=helper(root->right);\
        maxSum=max({maxSum,root->val+max(0,leftSum)+max(0,rightSum)});
        return root->val+max({0,leftSum,rightSum});
    }
    int maxPathSum(TreeNode* root) {
        int a=helper(root);
        return maxSum;
    }
};
