Approach-1(Brute Force)
TC:-O(N^2)
SC:-O(1)

Approach-2(Two Pointer)
TC:-O(N)
SC:-O(1)
int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int first = 0;
        int end = nums.size()-1;

        while( first < end){
            int num = (-(nums[first]));
            if(num == nums[end]){
                return nums[end];
            }
            else if(num < nums[end]){
                end--;
            }
            else{
                first++;
            }
        }
        return -1;
    }
