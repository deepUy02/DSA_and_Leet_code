Approach-1(Recursion)
TC-Exponential

#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a ,int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a ,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

int solve(int n ,int k){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k,k-1));
    }
    
    int ans = add(mul(solve(n-2,k) , k-1), mul(solve(n-1,k) , k-1));
    return ans;
}
int numberOfWays(int n, int k) {
    return solve(n , k);
}


Approach-2(Memorization)
TC-O(N)
SC-O(N)+O(N)

#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a ,int b){
    return (a%MOD  + b%MOD)%MOD;
}
int mul(int a ,int b){
    return ((a%MOD)* 1LL *(b%MOD))%MOD;
}

int solve(int n ,int k, vector<int>&dp){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k,k-1));
    }
    //Step-3
    if(dp[n] != -1)
        return dp[n];
    //Step-2
    dp[n] = add(mul(solve(n-2,k,dp) , k-1), mul(solve(n-1,k, dp) , k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    //Step-1    
    vector<int>dp(n+1, -1);
    return solve(n , k, dp);
}

Approach-3(Tabulation)
TC-O(N)
SC-O(N)

#include <bits/stdc++.h> 
#define MOD 1000000007
int add(int a ,int b){
    return (a%MOD  + b%MOD)%MOD;
}
int mul(int a ,int b){
    return ((a%MOD)* 1LL *(b%MOD))%MOD;
}

int solve(int n ,int k){
    vector<int>dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k,k-1));

    for (int i = 3; i <=n ; i++) {
        dp[i] = add(mul(dp[i - 2], k - 1), mul(dp[i - 1], k - 1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
    return solve(n , k);
}

Approach-4(Space Optimization)
TC-O(N)
SC-O(1)

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