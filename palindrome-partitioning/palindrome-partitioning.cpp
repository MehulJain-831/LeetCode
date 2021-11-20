class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(string s,int i,int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        dp[i][j] = 1;
        int b = i, e = j;
        while(b <= e){
            if(s[b] != s[e]){
                dp[i][j] = 0;
                break;
            }
            b++;
            e--;
        }
        return dp[i][j];
    }

    void rec(vector<vector<string>>& res, vector<string>& arr, string s, int start){
        if(start == s.length()){
            res.push_back(arr);
            return;
        }
        for(int i = start;i < s.length();i++){
            if(isPalindrome(s,start,i)){
                string temp = s.substr(start,i-start+1);
                arr.push_back(temp);
                rec(res,arr,s,i+1);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        dp.resize(s.length(), vector<int>(s.length(),-1));
        vector<vector<string>> res;
        vector<string> arr;
        rec(res,arr,s,0);
        return res;
    }
};