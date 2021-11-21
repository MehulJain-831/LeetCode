class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r-l)/2;
            int mid_num = nums[m];
            cout<<m<<endl;
            if(mid_num == target){
                return m;
            }
            if(mid_num >= nums[0] != target >= nums[0]){
                if(target >= nums[0]){
                    mid_num = INT_MAX;
                }
                else{
                    mid_num = INT_MIN;
                }
            }
            if(mid_num < target){
                l = m+1;
            }
            else{
                r = m;
            }
        }
        return (nums[r] == target) ? r : -1;
    }
     
};