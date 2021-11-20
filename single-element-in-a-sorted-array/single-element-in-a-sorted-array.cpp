class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = (l+r)/2;
            if(m&1){
                if(nums[m] == nums[m+1]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(nums[m] == nums[m+1]){
                    l = m;
                }
                else{
                    r = m;
                }
            }
        }
        return nums[r];
    }
};