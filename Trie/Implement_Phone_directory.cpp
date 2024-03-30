class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        //Assumption , word in CAPS
        int index=word[0]-'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //Recursion
        insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    void printSuggestions(TrieNode* curr, vector<string>&temp,string prefix){
        if(curr ->isterminal){
            temp.push_back(prefix);
            // return ;
        }
        for(char ch='a';ch<'z';ch++){
            TrieNode* next = curr->children[ch-'a'];
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>>output;
        string prefix = "";
        for(int i=0; i<str.length();i++){
            char lastchar = str[i];
            prefix.push_back(lastchar);
            //check for lastchar;
            TrieNode* curr = prev->children[lastchar-'a'];
            //if not found
            if(curr == NULL){
                break;
            }   
            //if found
            vector<string>temp;
            printSuggestions(curr ,temp , prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;

        }
        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t=new Trie();
    //Insert All contactList in trie;
    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insertWord(str);
    }
    //return ans;
    return t->getSuggestions(queryStr);
}