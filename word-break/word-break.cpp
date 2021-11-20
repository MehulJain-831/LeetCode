using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 

#define ll long long
#define ull unsigned ll
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define vvi vector<vi>
#define vvll vector<vll>
#define ff first
#define ss second
#define pb push_back
#define vpi vector<pi>
#define vpll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(),x.end()
#define fr(i,j,n) for(int i=j;i<n;++i)
#define rfr(i,j,n) for(int i=j; i>=n;--i)
#define MOD 1000000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX  
#define mp make_pair
#define endl "\n"
#define sz size()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


class Solution {
public:
    vi dp;
    bool rec(string s, uset<string>& dict, int start){
        if(start == s.length()){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        string temp = "";
        fr(i,start,(int)min(start+20, (int)s.length())){
            temp += s[i];
            if(dict.find(temp) != dict.end()){
                if(rec(s,dict,i+1)){
                    return true;
                }
                else{
                    dp[i+1] = 0;
                }
            }
        }
        return false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(301,-1);
        uset<string> dict;
        for(auto str : wordDict){
            dict.insert(str);
        }
        return rec(s,dict,0);
    }
};