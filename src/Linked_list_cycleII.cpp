/***Linked List Cycle II Total Accepted: 43501 Total Submissions: 139128 My Submissions Question Solution 
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?***/

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
    ListNode *detectCycle(ListNode *head) {
        
        
        bool hasCycle = false;
        
        ListNode*slow = head;
        ListNode*quick = head;
        auto count = 0;
        while(quick && quick->next)
        {
            quick = quick->next->next;
            slow = slow->next;
            count++;
            //当quick经过头结点时，表示头结点是环的起点直接返回即可
            if(quick == head)return head;
            if(quick == slow)
            {
                hasCycle = true;
                break;
            }
            
        }
        
        if(!hasCycle)return nullptr;
        //当不是都节点时slow放回起点，并且在quick和slow再次相遇时就是环的起点
        ListNode*tmp = slow;
        slow = head;
        while(count >= 0)
        {
            slow = slow->next;
            quick = quick->next;
            if(slow == quick)return slow;
            count--;
        }
        return nullptr;
    }
};