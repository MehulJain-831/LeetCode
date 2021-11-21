class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        int s = 0, e = x;
        while(s <= e){
            int parx = (s+e)/2;
            int pary = (x+y+1)/2 - parx;
            int xl = (parx == 0)?INT_MIN:nums1[parx-1];
            int xr = (parx == x)?INT_MAX:nums1[parx];
            int yl = (pary == 0)?INT_MIN:nums2[pary-1];
            int yr = (pary == y)?INT_MAX:nums2[pary];
            if(xl <= yr && xr >= yl){
                if((x+y)&1){
                    return max(xl,yl);
                }
                else{
                    return (float)(max(xl,yl)+min(xr,yr))/2;
                }
            }
            if(xl > yr){
                e = parx-1;
            }
            else{
                s = parx+1;
            }
        }
        return -1;
        
    }
};