class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int cost=grid[0][0]>0;
        if(cost<=k) dp[0][0][cost]=grid[0][0];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cost=grid[i][j]>0;
                for(int c=0;c<=k;c++)
                {
                    if (c - cost >= 0) {
                        if (i > 0 && dp[i-1][j][c-cost] != -1)
                            dp[i][j][c] = max(dp[i][j][c],
                                dp[i-1][j][c-cost] + grid[i][j]);

                        if (j > 0 && dp[i][j-1][c-cost] != -1)
                            dp[i][j][c] = max(dp[i][j][c],
                                dp[i][j-1][c-cost] + grid[i][j]);
                    }
                }
            }
        }
        int res=-1;
        for(int i=k;i>=0;i--)
        {
            res=max(res,dp[n-1][m-1][i]);
        }
        return res;
    }
};