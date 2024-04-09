Approach-1(Recursion + Memorization)
TC-O(N)
SC-O(N)
int solve(vector<int>&nums, int n, vector<int>&dp){
        //Base Case 
        if(n < 0)   return 0;
        if(n == 0)  return nums[0];
        //Step-3
        if(dp[n] != -1) return dp[n];
        //function call for the include element or not 
        int includecurr = solve(nums , n-2,dp) + nums[n];
        int excludecurr = solve(nums , n-1,dp) + 0;
        //Step-2
        dp[n] = max(includecurr , excludecurr);
        return dp[n];
 }
    
 int rob(vector<int>& nums) {
        int n = nums.size();
        //Step-1
        vector<int>dp(n,-1);
        int ans = solve(nums, n - 1,dp);
        return ans;
 }

Approach -2(Space Optimization)
TC-O(N)
SC-(1)
int rob(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1;i < nums.size(); i++){
            int includecurr = prev2 + nums[i];
            int excludecurr = prev1 + 0;

            int ans = max(includecurr , excludecurr);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }