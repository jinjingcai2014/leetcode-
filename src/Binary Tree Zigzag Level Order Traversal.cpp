/***Binary Tree Zigzag Level Order Traversal Total Accepted: 32579 Total Submissions: 123079 My Submissions Question Solution 
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is 
serialized on OJ.***/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >result;
        if(!root)return result;
        queue<TreeNode*>current,next_level;
        vector<int>inner_word;
        current.push(root);
        int i = 0;
        while(!current.empty())
        {
            TreeNode * tmp;
            tmp = current.front();
            current.pop();
            inner_word.push_back(tmp->val);
            
            if(tmp->left)
              next_level.push(tmp->left);
            if(tmp->right)
              next_level.push(tmp->right);
            
            if(current.empty())
            {
              i++;
              if(i%2 == 0)reverse(inner_word.begin(), inner_word.end());
              result.push_back(inner_word);
              swap(current, next_level);
              inner_word.clear();
             }
        }
        return result;
    }
};