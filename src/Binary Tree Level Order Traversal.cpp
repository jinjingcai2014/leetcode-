/***Binary Tree Level Order Traversal 
Total Accepted: 49301 Total Submissions: 166338 My Submissions Question Solution 
Given a binary tree, return the level order traversal of its 
nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int> >result;
    vector<int>vec_middle;
    queue<TreeNode *>current,next;
    if(!root)return result;
    
    current.push(root);
    //不取出current中每层元素压入到vec_middle，然后在压入result
    while(!current.empty()){//当current不为空时
        TreeNode *tmp; //定义临时节点
        tmp = current.front(); //取出在curren队列中的元素
        vec_middle.push_back(tmp->val);
        current.pop();
        
        if(tmp->left)
            next.push(tmp->left);
        if(tmp->right)
            next.push(tmp->right);
        
        //当current再次为空时代表该层结束
        if(current.empty()){
            result.push_back(vec_middle);
            swap(current, next);
            vec_middle.clear();
        }
        
    }
    
        return result;
    }
    
};