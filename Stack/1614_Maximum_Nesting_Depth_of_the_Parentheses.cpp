Approach:-1
TC:-O(N)
SC:-O(N)
//using stack
class Solution {
public:
    int maxDepth(string s) {
        
        stack<char>st;
        int ans = 0;
        for(auto &ch : s){

            if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                st.pop();
            }

            ans = max(ans , (int)st.size());

        }
        return ans;
    }
};

Approach-2
TC:-O(N)
SC:-O(1)
//counting the open brackets
class Solution {
public:
    int maxDepth(string s) {
        
        int openBrac = 0;
        int ans = 0;
        for(auto &ch : s){

            if(ch == '('){
                openBrac++;
            }
            else if(ch == ')'){
                openBrac--;
            }

            ans = max(ans , openBrac);

        }
        return ans;
    }
};