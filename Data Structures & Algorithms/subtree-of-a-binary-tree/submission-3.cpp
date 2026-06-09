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
    // bool isSame(TreeNode* root,TreeNode* sub){
    //     if(!root&&!sub) return true;
    //     if(!root||!sub) return false;
    //     if(root->val != sub->val) return false;
    //     return isSame(root->left,sub->left) && isSame(root->right,sub->right);
    // }
    // TreeNode* search(TreeNode* root, TreeNode* sub){
    //     if(!root && sub) return NULL;
    //     if(root->val==sub->val) return root;
    //     TreeNode* left=search(root->left,sub);
    //     if(left) return left;
    //     TreeNode* right=search(root->right,sub);
    //     if(right) return right;
    //     // return  || search(root->right,sub); 
    // }













    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        if(!subRoot||!root) return false;
        // if(!root) return false;
        if(root->val==subRoot->val){
            return isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        if(isSameTree(root,subRoot)) return true;

        return (isSubtree(root->left,subRoot)) || (isSubtree(root->right,subRoot));
    }
};
