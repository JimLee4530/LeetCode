class Solution {
public
    int search(vectorint& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left = right)
        {
            int mid = (right - left)2 + left;
            if(nums[mid] == target) return mid;
            if(nums[mid]  nums[right]){
                if(nums[mid]  target && target = nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else
            {
                if(nums[mid]  target && target = nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};