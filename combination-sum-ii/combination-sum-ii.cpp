class Solution {
public:
    void rec(vector<int>& candidates, vector<vector<int>>& res, vector<int>& arr,int sum, int target, int ind){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(arr);
            return;
        }
        
        for(int i = ind; i < candidates.size(); i++){
            if(i == ind || candidates[i] != candidates[i-1]){
                if(sum + candidates[i] > target)
                    break;
                arr.push_back(candidates[i]);
                rec(candidates,res,arr,sum+candidates[i],target,i+1);
                arr.pop_back();    
            }
            
        }     
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        rec(candidates,res,arr,0,target,0);
        return res;
    }
};