Approach-1(Recursion)
TC:-exponential
SC:-O(n)
int solve(vector<int>&num, int x){
    //base Case
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }
    int mini = INT_MAX;
    for(int i = 0;i < num.size();i++){
        int ans = solve(num, x-num[i]);
        if(ans != INT_MAX){
            mini = min(mini , ans+1);
        }
    }
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
    int ans = solve(num , x);
    if(ans == INT_MAX){
        return -1;
    }
}

Approach-2(Recursion + Memorization)
TC:-O(x*n)
SC:-O(x)
int solve(vector<int>&num, int x , vector<int>&dp){
    //base case
    if(x == 0)  return 0;
    if(x < 0)   return INT_MAX;

    //Step-3
    if(dp[x] != -1) return dp[x];
    //Step-2
    int mini = INT_MAX;
    for(int i = 0;i < num.size(); i++){
        int ans = solve(num , x-num[i],dp);
        if(ans != INT_MAX){
            mini = min(mini , ans+1);
        }
    }
    dp[x] = mini;
    return mini;
}
int minimumElements(vector<int> &num, int x)
{
        //Step-1
        vector<int>dp(x + 1, -1);
        int ans = solve(num , x , dp);

        if(ans == INT_MAX)
            return -1;
        else
            return ans;
}

Approach-3(Tabulation)
TC:-O(x*n)
SC:-O(x)
int solve(vector<int>&num , int x){
    vector<int>dp(x+1 , INT_MAX);
    dp[0] = 0;

    for(int i = 1;i <= x;i++){
        //trying to solve for every amount figure from 1 to x;
        for(int j = 0; j < num.size(); j++){
            if(i - num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i] , 1 + dp[i - num[j]]);
            }
        }
    }
    if(dp[x] == INT_MAX)    return -1;
    else    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    return solve(num , x);
}

//Space Optimization is not possible because there is not any fix dependency of any element to other elements.