
class Solution {
private:
    vector<int> dp;
public:
    int find_max(vector<int>& nums,int node){
        if(dp[node] != -1){
            return dp[node];
        }
        if(node == 0){
            return dp[node] = nums[0];
        }
        if(node == 1){
            return dp[node] = max(nums[0],nums[1]);
        }
        return dp[node] = max(nums[node]+find_max(nums,node-2), find_max(nums,node-1));
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return find_max(nums,nums.size()-1);
    }
};