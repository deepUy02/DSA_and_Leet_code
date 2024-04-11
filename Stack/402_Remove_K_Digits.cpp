TC-O(2*N)
SC-O(N)

string removeKdigits(string num, int k) {
        
        //initialise a stack data stucture ans push the digits of the 
        //given num string
        //CASE-1 if the top of the stack is greater then the next element of the num
        //then pop the top of the stack 
        //else push in the stack 
        //at last we get the minimum number as possible
        string ans = "";
        for(int i = 0;i < num.size(); i++){
            
            while(ans.length() > 0 && ans.back() > num[i] && k > 0){
                ans.pop_back();
                k--;
            }
            if(ans.length() > 0 || num[i] != '0'){
                ans.push_back(num[i]);
            }
        }
        while(ans.length() > 0 && k > 0){
            ans.pop_back();
            k--;
        }
        if(ans == ""){
            return "0";    
        }
        return ans;
    }