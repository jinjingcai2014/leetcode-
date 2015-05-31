/**Single Number II Total Accepted: 49850 Total Submissions: 143002 My Submissions Question Solution 
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Show Tags
Have you met this question in a real interview? ***/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto len = nums.size();
        if(len == 1 )return nums[0];
        
        sort(nums.begin(), nums.end());
        
        for(auto i = 2; i <= len-2; )
        {
            if(nums[i-2] == nums[i])i = i+3;
            else return nums[i-2];
        }
        return nums[len-1];
    }
};