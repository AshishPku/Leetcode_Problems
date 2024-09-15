// a.length == 4
// 4 <= b.length <= 105
// -105 <= a[i], b[i] <= 105
class Solution {
public:
    long long func(int i,int j,int &n,vector<int>&a,vector<int>&b,vector<vector<long long>>&dp){
        if(i<n){
            if(j<4){
                if(dp[i][j]!=-1) return dp[i][j];
            return dp[i][j]=max((long long)b[i]*a[j]+func(i+1,j+1,n,a,b,dp),func(i+1,j,n,a,b,dp));
            }else{
                return 0;
            }
        }else{
            if(j==4) return 0;
            else return -1e8;
        }
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=b.size();
        vector<vector<long long>> dp(n,vector<long long>(4,-1));
        return func(0,0,n,a,b,dp);
    }
};