/***Same Tree Total Accepted: 59650 Total Submissions: 141983 My Submissions Question Solution 
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Show Tags
Have you met this question in a real interview? Yes  No
Discuss

****/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)return true;
        if(!p || !q || p->val != q->val)
            return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right, q->right);
        
    }
};