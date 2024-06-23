    Using priority Queue
    //Time complexity:-O(n*log(n))
    //Space complexity:-O(2*n)
     typedef pair<int,int>P;
     int longestSubarray(vector<int>& nums, int limit) {
         int n = nums.size();

         priority_queue<P,vector<P>>maxPQ;
         priority_queue<P,vector<P>,greater<P>>minPQ;

         int start = 0;
         int end = 0;
         int ans = 0;
         while(end < n){
             maxPQ.push({nums[end],end});
             minPQ.push({nums[end],end});

             while(maxPQ.top().first - minPQ.top().first > limit){
                 start = min(maxPQ.top().second, minPQ.top().second) + 1;
                 while(maxPQ.top().second < start){
                     maxPQ.pop();//------>log(n)
                 }
                 while(minPQ.top().second < start){
                     minPQ.pop();//------>log(n)
                 }
             }
             ans = max(ans , end-start+1);
             end++;
         }
         return ans;
     }

    Using multiSet:
    //it has properties of find maximum ans minimum 
    //it has properties of delete element 
    //Time complexity:-O(log(n));
    //Space Complexity:-O(n)
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int>st;

        int start = 0;
        int end = 0;
        int ans = 0;
        while(end < n){
            st.insert(nums[end]);

            while(*st.rbegin() - *st.begin() > limit){
                st.erase(st.find(nums[start]));
                start++;
            }
            ans = max(ans , end-start+1);
            end++;
        }
        return ans;
    }