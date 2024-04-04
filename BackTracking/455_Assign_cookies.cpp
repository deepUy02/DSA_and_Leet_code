class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int i = 0;
        int j = 0;
        while(i < g.size() && j < s.size()){

            if(g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};