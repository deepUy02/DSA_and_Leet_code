int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sqrStuCnt = 0;
        int cirStuCnt = 0;

        for(int i = 0;i < students.size();i++){
            if( students[i] == 1){
                sqrStuCnt++;
            }
            else{
                cirStuCnt++;
            }
        }
        for(int i = 0;i < sandwiches.size();i++){
            if(sandwiches[i] == 1){
                if(sqrStuCnt > 0){
                    sqrStuCnt--;
                }
                else{
                    break;
                }
            }
            if(sandwiches[i] == 0){
                if(cirStuCnt > 0){
                    cirStuCnt--;
                }
                else{
                    break;
                }
            }
        }
        return sqrStuCnt + cirStuCnt;
    }