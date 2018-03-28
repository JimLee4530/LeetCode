class Solution {
public
    vectorint intersection(vectorint& nums1, vectorint& nums2) {
        setint nums1Set(nums1.begin(), nums1.end());
        setint nums2Set(nums2.begin(), nums2.end());
        vectorint res;
        setintiterator iter;
        for(iter = nums1Set.begin();iter!=nums1Set.end();++iter){
            if(nums2Set.find(iter) != nums2Set.end())
                res.push_back(iter);
        }
        return res;
    }
};