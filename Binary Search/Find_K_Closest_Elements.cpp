class Solution {
public:
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-1;
        int p;
        while(left+1<right){
            int mid = left+(right-left)/2;
            if(arr[mid] == x)
            {
                right = mid;
                break;
            }
            if(arr[mid]>x)
                right = mid;
            if(arr[mid]<x)
                left = mid;
        }
        p = right<0?0:right;
        cout<<right<<endl;
        int i = p-1; 
        int j = p;
        while(k--) (i<0||(j<arr.size()&&abs(arr[i]-x)>abs(arr[j]-x)))?j++:i--;
        return vector<int>(arr.begin() + i+1, arr.begin() + j );
    }
};