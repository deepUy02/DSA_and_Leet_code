Approach-1(Recursion)
#include <bits/stdc++.h> 
int solve(int index , vector<int> &heights){
    if(index == 0){
        return 0;
    }
    int left = solve(index -1 , heights) + abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if(index > 1)
        right = solve(index-2, heights) + abs(heights[index]-heights[index-2]);
    return min(left, right);   
}
int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights);
}

Approach-2(Recursion + Memo)
int solve(int index , vector<int> &heights, vector<int>&dp){
    if(index == 0){
        return 0;
    }
    if(dp[index] != -1){
        return dp[index];
    }
    int left = solve(index -1 , heights, dp) + abs(heights[index]-heights[index-1]);
    int right = INT_MAX;
    if(index > 1)
        right = solve(index-2, heights, dp) + abs(heights[index]-heights[index-2]);
    return dp[index] = min(left, right);   
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
    return solve(n-1, heights, dp);
}

Approach-3(Tabulation)
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n, 0);

    dp[0] = 0;
    for(int i = 1;i < n;i++){
        int firstStep = dp[i-1] + abs(heights[i]- heights[i-1]);
        int secondStep = INT_MAX;
        if(i > 1)
            secondStep = dp[i-2] + abs(heights[i] - heights[i-2]);
        
        dp[i] = min(firstStep, secondStep);
    }
    return dp[n-1];
}

Approach-4(Space Optimization)

int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;

    for(int i = 1;i < n;i++){
        int firstStep = prev1 + abs(heights[i]- heights[i-1]);
        int secondStep = INT_MAX;
        if(i > 1)
            secondStep = prev2 + abs(heights[i] - heights[i-2]);
        
        int current = min(firstStep, secondStep);
        prev2 = prev1;
        prev1 = current ;
    }
    return prev1;
}