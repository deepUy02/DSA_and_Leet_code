Approack-1 //Using Stack
string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int>invalid;

        for(int i = 0; i< s.length();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    invalid.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        //when only open brackets
        while(!st.empty()){
            invalid.insert(st.top());
            st.pop();
        }

        string ans = "";

        for(int i=0;i< s.length();i++){
            if(invalid.find(i) == invalid.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }

Approacj-2 //counting open and close brackets
string minRemoveToMakeValid(string s) {
        string ans="";
        int openBrac = 0;

        for(int i = 0;i< s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans.push_back(s[i]);
            }
            else if(s[i] == '('){
                openBrac++;
                ans.push_back(s[i]);
            }
            else if(openBrac > 0){
                openBrac--;
                ans.push_back(s[i]);
            }
        }

        string final_ans = "";

        int close_brac = 0;
        for(int i = ans.length()-1 ;i >= 0 ;i--){
            if(ans[i] >= 'a' && ans[i] <= 'z'){
                final_ans.push_back(ans[i]);
            }
            else if(ans[i] == ')'){
                close_brac++;
                final_ans.push_back(ans[i]);
            }
            else if(close_brac > 0){
                close_brac--;
                final_ans.push_back(ans[i]);
            }
        }
        reverse(begin(final_ans),end(final_ans));
        return final_ans;
    }
