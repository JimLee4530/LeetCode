class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int lenNums1 = nums1.size();
//         int lenNums2 = nums2.size();
//         if(!lenNums1 && !lenNums2)
//             return 0.0;
    
//         int target = (lenNums1+lenNums2+1)/2;
//             int x = findKth(nums1, 0, lenNums1-1, nums2, 0, lenNums2-1, target);
//             if((lenNums1+lenNums2)%2==0){
//                 int y= findKth(nums1, 0, lenNums1-1, nums2, 0, lenNums2-1, target+1);
//                 return (x+y)/2.0;
//             }
//         return x;
        //solution 2
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(), nums1.end());
		double mid = 0;
		int i;
		i = nums1.size() / 2;
		if (nums1.size() % 2 == 0)
		{
			mid = nums1[i] + nums1[i - 1];
			mid /= 2;
		}
		else
			mid = nums1[i];

		return mid;
    }
private:
    int findKth(vector<int>& numsA, int aLeft, int aRight, vector<int>& numsB, int bLeft, int bRight, int target){
        if(aLeft>aRight) return numsB[bLeft+target-1];
        if(bLeft>bRight) return numsA[aLeft+target-1];
        
        int aMid = aLeft + (aRight-aLeft)/2;
        int bMid = bLeft + (bRight-bLeft)/2;
        
        if(numsA[aMid]<=numsB[bMid]){
            if(target<=(aMid-aLeft)+(bMid-bLeft)+1)
                return findKth(numsA, aLeft, aRight, numsB, bLeft, bMid-1, target);
            else
                return findKth(numsA, aMid + 1, aRight, numsB, bLeft, bRight, target-(aMid-aLeft)-1);
        }else{
            if(target<=(aMid-aLeft)+(bMid-bLeft)+1)
                return findKth(numsA, aLeft, aMid-1, numsB, bLeft, bRight, target);
            else
                return findKth(numsA, aLeft, aRight, numsB, bMid+1, bRight, target-(bMid-bLeft)-1);
        }
    }
};