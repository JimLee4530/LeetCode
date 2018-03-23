class Solution {
public
    vectorint searchRange(vectorint& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vectorint res(2, -1);
        if(nums.size() == 0) return res;
        while(left+1  right)
        {
            int mid = left+(right-left)2;
            if(nums[mid]  target)            
                left = mid;
            else
                right = mid;
        }
        
         if(nums[right] != target)
             return res;
        if(nums[left] == target)
            res[0] = left;
        else if(nums[right] == target) 
            res[0] = right;
        else
            return res;
        left = 0;
        right = nums.size()-1;
        while(left+1  right)
        {
            int mid = left+(right-left)2;
            if(nums[mid] = target)            
                left = mid;
            else
                right = mid;
        }
        if(nums[right] == target)
            res[1] = right;
        else 
            res[1] = left;
        return res;
    }
};