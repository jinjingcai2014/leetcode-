/***Binary Tree Level Order Traversal II 
Total Accepted: 39830 Total Submissions: 128529 My Submissions Question Solution 
Given a binary tree, return the bottom-up level order 
traversal of its nodes' values. (ie, from left to right, 
level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.****/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        vector<int>vec_middle;
        queue<TreeNode*>current, next;
        if(!root)return result;
        
        current.push(root);
        while(!current.empty()){
            TreeNode *tmp;
            tmp = current.front();
            current.pop();
            vec_middle.push_back(tmp->val);
            
            if(tmp->left)
                next.push(tmp->left);
            if(tmp->right)
                next.push(tmp->right);
            
            if(current.empty())
            {
              result.push_back(vec_middle);
              swap(current, next);
              vec_middle.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};