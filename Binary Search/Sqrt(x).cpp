class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        int left = 0;
        int right = x;
        while(left <= right){
            int mid = (left+right)/2;
            if((long)mid*mid == x)
                return mid;
            else if((long)mid*mid > x )
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
        // long r = x;
        // while (r*r > x)
        //     r = (r + x/r) / 2;
        // return r;
    }
};