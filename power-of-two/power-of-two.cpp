class Solution {
public:
    bool isPowerOfTwo(int n) {
        // int n = 4;
        // int m = 3;
        // cout<<(m&-m);
        if(n <= 0){
            return false;
        }
        return ((n&-n) == n);
        // return true;
    }
};