TC-O(N)
TC-O(1)
//two important idea is that if you consider the first element then skip 
//last element and if include last element then skip first element
int solve(vector<int>&nums){
        int n = nums.size();

        int prev2 = 0;
        int prev1 = nums[0];

        for(int i = 1;i< n; i++){
            int includecurr = prev2 + nums[i];
            int excludecurr = prev1 + 0;
            int ans = max(includecurr , excludecurr);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>first;
        vector<int>second;

        if(n == 1)  return nums[0];

        for(int i = 0;i < n;i++){
            if(i != n - 1){
                first.push_back(nums[i]);
            }
            if(i != 0){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }