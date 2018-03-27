class Solution {
public
    int findMin(vectorint& nums) {
        int left = 0;
        int right = nums.size()-1;
        return findMin(nums, left, right);
    }
private
    int findMin(vectorint& nums, int left, int right)
    {
        int min = nums[left];
        while(left+1  right){
            int mid = (right - left)2 + left;
            if(nums[mid]  nums[right])
                right = mid;
            else if (nums[mid]  nums[right])
                left = mid;
            else{
                int min1 = findMin(nums, left, mid-1);
                int min2 = findMin(nums, mid+1, right);
                min = min1min2min2min1;
                return min;
            }
        }
        return nums[right]=nums[left]nums[left]nums[right];
    }
};