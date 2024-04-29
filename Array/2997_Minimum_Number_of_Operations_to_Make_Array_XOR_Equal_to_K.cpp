class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = 0;
        for(auto & i: nums){
            total ^= i;
        }

        int diff = (total^k);
        return __builtin_popcount(diff);
    }
};