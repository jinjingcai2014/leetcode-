/***Reverse Nodes in k-Group Total Accepted: 32481 Total Submissions: 127381 My Submissions Question Solution 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5***/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>vec;
        if(k == 1)return head;
        
        ListNode*current = head;
        ListNode*nextnode = head;
        int m = k;
        while(current && current->next)
        {
            k = m;
            while(k >= 1)
            {
                vec.push_back(nextnode->val);
                k--;
                if(nextnode->next)
                    nextnode = nextnode->next;
                else break;
            }
            
            int len = vec.size() -1;
            if(vec.size() == m)
            {
                while(len >= 0)
                {
                    current->val = vec[len];
                    current = current->next;
                    len--;
                }
                vec.clear();
                
            }
            else break;
            
        }
        return head;
    }
};