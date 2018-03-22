class Solution {
public
    int findMin(vectorint& nums) {
        
        int left = 0;
        int right = nums.size()-1;
        int min = nums[0];
         if(nums.size() == 1)
             return nums[0];
        while(left = right){
            int mid = (right - left)2 + left;
            if(min  nums[mid])
                min = nums[mid];
            if(nums[mid]  nums[right])
                right = mid - 1;
            else
                left = mid + 1;
        }
         if(left != nums.size() && minnums[left])
             return nums[left];
        return min;
    }
};