Approach-1 //using traversing

int lengthOfLastWord(string s) {
    int i = s.length() - 1;
    int length = 0;
    while(i >= 0 && s[i] == ' '){
       i--;
    }
    while(i >= 0 && s[i] != ' '){
       length++;
       i--;
    }
    return length;
}

Approach-2 //Using STL

int lengthOfLastWord(string s) {
    int index = s.find_last_not_of(' ') + 1;
        
    s.erase(index);

    int lastSpaceIndex = s.find_last_of(' ');
    if(lastSpaceIndex == string::npos){
       return s.length();
    }
    return s.length() - lastSpaceIndex -1;
}