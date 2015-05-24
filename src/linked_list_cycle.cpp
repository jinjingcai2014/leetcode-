/***Linked List Cycle Total Accepted: 59624 Total Submissions: 164140 My Submissions Question Solution 
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

Show Tags
****/
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
    bool hasCycle(ListNode *head) {
        if(!head)return false;
        if(!head->next)return false;
        
        
        ListNode *quick;
        ListNode*slow;
        quick = head;
        slow = head;
        
        while(quick &&quick->next)
        {
            quick = quick->next->next;
            slow = slow->next;
            if(slow == quick)return true;
            
        }
        return false;
    }
};


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
    bool hasCycle(ListNode *head) {
        set<ListNode*>listnode;
        
        for(; head; head = head->next)
        {
            if(listnode.find(head) != listnode.end())return true;
            else listnode.insert(head);
        }
        return false;
    }
};