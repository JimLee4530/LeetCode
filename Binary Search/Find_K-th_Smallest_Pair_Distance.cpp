class Solution {
    
    // binary search and slide windows
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size()-1]-nums[0];
        while(left < right){
            int mid = (left + right)/2;
            if(possible(nums, mid, k))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
private:
    bool possible(vector<int>& nums, int guess, int k)
    {
        int count = 0;
        int left = 0;
        int len = nums.size();
        for(int right = 0;right < len; right++)
        {
            while(nums[right] - nums[left] > guess)
                left++;
            count += right - left;
        }
        if(count >= k)
            return true;
        else
            return false;
    }
};