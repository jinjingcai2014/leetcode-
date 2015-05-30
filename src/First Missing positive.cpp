/**First Missing Positive 
Total Accepted: 36832 Total Submissions: 160391 My Submissions Question Solution 
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.****/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(auto i = 0; i < len; )
        {
            if(nums[i] == i+1)
                i++;
            else if((nums[i] < i || nums[i] > len) ||(nums[nums[i] - 1] == nums[i]))
            {
                len--;
                nums[i] = nums[len];
            }
            else 
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return len+1;
    }
};