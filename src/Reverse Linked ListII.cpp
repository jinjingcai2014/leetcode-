/*****Reverse Linked List II Total Accepted: 39853 Total Submissions: 152454 My Submissions Question Solution 
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.********/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *head1 = head;
        ListNode *mNode = head;
        if(m == n)return head;
        int i = 1;
        while(i < m)
        {
            mNode = mNode->next;
            i++;
        }
        
        ListNode *temp = mNode;
        vector<int>vecValue;
        while(i < n)
        {
            vecValue.push_back(mNode->val);
            mNode = mNode->next;
            i++;
        }
        vecValue.push_back(mNode->val);
        
        int length = vecValue.size()-1;
        while(length >= 0)
        {
            temp->val = vecValue[length];
            length--;
            temp = temp->next;
        }
        return head1;
          
    }
    
};