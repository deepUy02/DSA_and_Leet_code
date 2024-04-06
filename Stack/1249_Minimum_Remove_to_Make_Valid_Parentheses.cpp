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