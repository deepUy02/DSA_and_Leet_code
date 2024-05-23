Approach-1(Recursion)
int solve(vector<int>&height, int index , int k){
        if(index == 0)   return 0;
        
        int minimumSteps = INT_MAX;
        
        for(int j = 1;j <= k;j++){
            if(index - j >= 0) {
                int jump = solve(height ,index-j ,k) + abs(height[index]-height[index-j]);
                minimumSteps = min(minimumSteps , jump);
            } 
        }
        return minimumSteps;
}
int minimizeCost(vector<int>& height, int n, int k) {
    return solve(height, n-1,k,dp);
}
    
Approach-2(Rec + Memo)
int solveMemo(vector<int>&height,int index, int k,vector<int>&dp){
        if(index == 0)  return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int minimumSteps = INT_MAX;
        
        for(int j = 1;j <= k;j++){
            if(index - j >= 0){
                int jump = solveMemo(height , index - j ,k,dp) + abs(height[index]-height[index - j]);
                minimumSteps = min(minimumSteps , jump);
            }
        }
   return dp[index] = minimumSteps;
 }
int minimizeCost(vector<int>& height, int n, int k) {
    vector<int> dp(n+1 , -1);
    return solveMemo(height, n-1,k,dp);
}

Approach-3(Tabulation)

int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n, 0);
        dp[0] = 0;
        for(int i = 1;i< n ;i++){
            int minimumSteps = INT_MAX;
            for(int j = 1;j <= k;j++){
                if(i-j>=0){
                    int jump = dp[i-j] + abs(height[i]-height[i-j]);
                    minimumSteps = min(minimumSteps, jump);
                }
            }
            dp[i] = minimumSteps;
     }
    return dp[n-1];
}