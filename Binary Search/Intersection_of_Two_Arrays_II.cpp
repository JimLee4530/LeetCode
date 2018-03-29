class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // set<int> nums2Set(nums2.begin(), nums2.end());
        // vector<int>::iterator iter = nums1.begin();
        // vector<int> res;
        // while(iter!=nums1.end())
        // {
        //     if(nums2Set.find(*iter)!=nums2Set.end())
        //     {
        //         res.push_back(*iter);
        //         nums2Set.erase(*iter);
        //     }
        //     iter++;
        // }
        // return res;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};