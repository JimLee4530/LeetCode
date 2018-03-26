class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(letters[mid] <= target)
                left = mid+1;
            if(letters[mid] > target)
                right = mid;
        }
        if(letters[right] >target)
            return letters[right];
        else
            return letters[0];
    }
};