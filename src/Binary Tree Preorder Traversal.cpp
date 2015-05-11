/**Binary Tree Preorder Traversal 
Total Accepted: 65881 Total Submissions: 181516 My Submissions Question Solution 
Given a binary tree, return the preorder traversal of its 
nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it 
iteratively?***/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        if(!root)return result;
        
        result.push_back(root->val);
        visitVal(root->left,result);
        visitVal(root->right, result);
        return result;
    }
    vector<int> visitVal(TreeNode *T, vector<int>&res )
    {
        if(!T)return res;
        res.push_back(T->val);
        visitVal(T->left, res);
        visitVal(T->right, res);
        return res;
    }
    
};