class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return 0;
        if(grid[i][j]==0||grid[i][j]==2)
            return 0;
        grid[i][j]=2;
        
        return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int count=1;
                if(grid[i][j]==1)
                {
                    ans=max(ans,dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};