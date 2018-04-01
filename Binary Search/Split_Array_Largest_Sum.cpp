class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0;
        long long right = 0;
        for(int num : nums){
            left = max(left, (long long)num);
            right += num;
        }
        
        while(left < right){
            long long mid = left + (right - left)/2;
            if (possible(nums, mid, m-1))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
private:
    bool possible(vector<int>& nums, int subSum, int cuts){
        int acc= 0;
        for(int num : nums){
            if (num > subSum)
                return false;
            else if(acc + num <= subSum)
                acc += num;
            else
            {
                acc = num;
                cuts--;
                if (cuts < 0)
                    return false; 
            }
        }
        return true;
    }
};

