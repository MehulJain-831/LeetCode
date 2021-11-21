class Solution {
public:
    int cnt(int n){
        int c = 0;
        while(n > 0){
            c++;
            n = n&(n-1);
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        
        for(int i = 0; i <= n; i++){
            res[i] = cnt(i);
        }
        return res;
    }
};