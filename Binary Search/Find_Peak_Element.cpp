class Solution {
public
    int findPeakElement(vectorint& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums.size() == 1)
            return 0;
        if(nums[0]nums[1])
            return 0;
        if(nums[right]  nums[right-1])
            return right;
        while(left  right){
            int mid = (right - left)2 + left;
            if(nums[mid]nums[mid+1] && nums[mid]nums[mid-1])
                return mid;
            if(nums[mid]nums[mid+1])
                left = mid+1;
            else if(nums[mid]nums[mid-1])
                right = mid-1;
        }
        if(left != nums.size() && nums[left-1]nums[left] && nums[left+1]nums[left])
            return left;
        return -1;
    }
};