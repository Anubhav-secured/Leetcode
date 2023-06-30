class Solution {
public:
    int rec(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++)
        {
            int cost=cuts[j+1]-cuts[i-1]+rec(i,k-1,cuts,dp)+rec(k+1,j,cuts,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return rec(1,c,cuts,dp);
    }
};