/**Maximum Gap Total Accepted: 14311 Total Submissions: 59107 My Submissions Question Solution 
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        auto len = nums.size();
        if(len < 2)return 0;
        
        sort(nums.begin(), nums.end());
        
        auto sum = 0;
        for(auto i = 1; i <= len-1; i++)
        {
            if(sum <= (nums[i] - nums[i-1]))
                sum = nums[i] - nums[i-1];
            else continue;
        }
        
        return sum;
    }
};