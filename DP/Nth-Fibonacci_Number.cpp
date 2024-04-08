1-Top-Down Approach
//TC-O(n)
//SC-O(n)+O(n)
#include<bits/stdc++.h>
using namespace std;
int fib(int n , vector<int>&dp){
        //base case
        if(n <= 1){
                return n;
        }
        //Step-2
        if(dp[n] != -1){
                return dp[n];
        }
        //Step-3
        dp[n] = fib(n-1 , dp) + fib(n-2 , dp);
        return dp[n];
}
int main()
{
        int n;
        cin>>n;
        //Step-1
        vector<int>dp(n+1);

        for(int i = 0;i <= n;i++){
                dp[i] = -1;
        }
        cout<<fib(n, dp)<<endl;
        return 0;
}

2-Bottom-up Approach
//TC-O(N)
//SC-O(N)
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin>>n;
        //Step-1
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i  <= n; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }
        cout<<dp[n]<<endl;
}

3-Space Optimization Approach
//TC-O(n)
//SC-O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
       int n;
       cin>> n;

        if( n == 0)     return n;
       int prev1 = 1;
       int prev2 = 0;

       for(int i = 2;i <= n;i++){
               int curr = prev1+ prev2;
               prev2 = prev1;
               prev1=curr;
       }
       cout<< prev1<<endl;
}