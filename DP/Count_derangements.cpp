Approach1-(Recursion)
#define MOD 1000000007
long long int countDerangements(int n) {
    //base case
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    int ans = (((n-1)%MOD) *((countDerangements(n-2))%MOD + (countDerangements(n-1))%MOD))%MOD;
    return ans;
}


Approach-2(Recursion + Memorization)

#define MOD 1000000007
#include<bits/stdc++.h>
long long int solve(int n , vector<long long int > &dp){
    //base case
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    //Step-3
    if(dp[n] != -1){
            return dp[n];
    }
    //Step-2
    dp[n] = (((n-1)%MOD) *((solve(n-1,dp)%MOD) + (solve(n-2,dp)%MOD))%MOD);
    return dp[n];
}
long long int countDerangements(int n) {
    //Step-1
    vector<long long int>dp(n+1, -1);
    return solve(n, dp);
}

Approach-3(Tabulation)

#define MOD 1000000007
#include<bits/stdc++.h>
long long int solve(int n){
    //base case
    vector<long long int >dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i = 3;i <= n; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        long long int sum = (first + second);
        long long int ans = ((i-1)*sum)%MOD;
        dp[i] = ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    return solve(n);
}

Approach-4(Space Optimization)

#define MOD 1000000007
#include<bits/stdc++.h>
long long int solve(int n){
    //base case
    long long int prev1 = 0;
    long long int prev2 = 1;

    for(int i = 3;i <= n; i++){
        long long int first = prev2%MOD;
        long long int second = prev1%MOD;
        long long int sum = (first + second);
        long long int ans = ((i-1)*sum)%MOD;
        prev1 = prev2;
        prev2= ans;

    }
    return prev2;

}
long long int countDerangements(int n) {
    return solve(n);
}