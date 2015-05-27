/**Single Number Total Accepted: 70551 Total Submissions: 156338 My Submissions Question Solution 
Given an array of integers, every element appears twice except for one. 
Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?***/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto len = nums.size();
        if(len == 1)return nums[0];
        
        for(int i = 1; i < len-1; )
        {
            if(nums[i-1] == nums[i])i += 2;
            else return nums[i-1];
        }
        return nums[len-1];
    }
};


//另外一种方法
//The trick is: A^B^A=B

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int first = nums[0];
        for(int i = 1; i<nums.size();i++) {
            first = first ^ nums[i];
        }
        return first;
    }
};