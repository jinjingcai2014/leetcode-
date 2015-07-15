/**Rotate Array Total Accepted: 32916 Total Submissions: 183940 My Submissions Question Solution 
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if(len == 1)return ;
        if((len == k) ||( k == 0))return ;
        //循环求出k
        if(len < k)k = k % len;
        
        myratote(nums, 0, len-k-1);
        myratote(nums, len-k, len-1);
        myratote(nums, 0, len-1);
    }
    
    void myratote(vector<int>& nums, int from, int to)
    {
        int temp;
        while(from < to)
        {

            temp = nums[from];
            nums[from++] = nums[to];
            nums[to--] = temp;
        }
    }
};