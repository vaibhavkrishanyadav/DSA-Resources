// 6. Zigzag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> posArr(numRows);
        int rows=0;
        bool checker = false;
        string ans;
        int i=0;
        
        if(numRows == 1)
            return s;
        
        while(i<s.length()){
            if(checker == false){
                if(rows == numRows-1){
                    checker = true;
                    posArr[rows].push_back(s[i]);
                    rows--;
                    if(rows == 0)
                        checker = false;
                }else{
                    posArr[rows].push_back(s[i]);
                    rows++;
                }
            }
            else{
                posArr[rows].push_back(s[i]);
                rows--;
                if(rows == 0)
                    checker = false;
            }
            i++;
        }
        
       for(int i=0;i<numRows;i++)
           ans += posArr[i];
       
        
        return ans;
    }
};
