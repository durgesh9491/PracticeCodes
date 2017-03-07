/*
 * https://www.interviewbit.com/problems/dungeon-princess/
 */
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = (int)A.size();
    int n = (int)A[0].size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1 , INT_MAX));
    
    dp[m-1][n] = dp[m][n-1] = 1;
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            dp[i][j] = min(dp[i][j+1],dp[i+1][j]) - A[i][j];
            if(dp[i][j] <= 0) dp[i][j] = 1;
        }
    }
    return dp[0][0];
}


/*
 * https://www.interviewbit.com/problems/min-sum-path-in-triangle
 */

int Solution::minimumTotal(vector<vector<int> > &A) {
    int m = A.size();
    vector<vector<int> > dp(2, vector<int> (m + 1, INT_MAX));
    
    dp[0][0] = A[0][0]; 
    for(int i = 1; i < m; i++){
        for(int j = 0; j <= i; j++){
            if(j > 0)
            dp[1][j] = min(dp[0][j], dp[0][j-1]) + A[i][j];
            else 
            dp[1][j] = dp[0][j] + A[i][j];
        }
         for(int j = 0; j <= i; j++) dp[0][j] = dp[1][j];
        
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; i++) ans = min(ans, dp[0][i]);
    return ans;
}

/*
 * https://www.interviewbit.com/problems/unique-paths-in-a-grid/
 */
 
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int  m = A.size();
    int n = A[0].size();
    vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
    
    dp[0][0] = !A[0][0];
    for(int i = 1; i < m; i++){
        if(!A[i][0]) dp[i][0] = dp[i-1][0];
    }
    for(int i = 1; i < n; i++){
        if(!A[0][i]) dp[0][i] = dp[0][i-1];
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(!A[i][j])
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

