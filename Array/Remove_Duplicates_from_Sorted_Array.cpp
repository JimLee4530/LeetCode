class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int count = 1;
        int i = nums[0];
        for(int num : nums){
            if(num != i){
                nums[count++] = num;
                i=num;
            }
        }
        return count;
    }
};