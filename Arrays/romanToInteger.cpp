class Solution {
public:
    string let = "IVXLCDM";
    
    int findIndx(char c){
        int indx = 0;
        for (int i = 0; i < let.size(); i++){
            if(c == let[i]){
                return i;}}
        return indx;
    }
    int romanToInt(string s) {
        int result = 0, letVal [] = {1, 5, 10, 50, 100, 500, 1000};
        if(s.size() == 1){
            result += letVal[findIndx(s[0])];
        }
        for (int i = s.size()-1; i > 0; i--){
            int in = findIndx(s[i]);
            if(in % 2 == 0){
                if(findIndx(s[i-1]) == in-2 && in > 0){
                    result+=letVal[in]-letVal[in-2];
                    i--;
                }
                else if(findIndx(s[i-1]) == in){
                    result+=letVal[in]+letVal[in];
                    if(i > 2 && findIndx(s[i-2]) == in){
                        result+=letVal[in];
                        i--;                        
                    }
                    i--;
                }
                else{
                    result+=letVal[in];
                }
            }
            else{
                if(findIndx(s[i-1]) == in-1){
                    result+=letVal[in]-letVal[in-1];
                    i--;
                }
                else{
                    result+=letVal[in];
                }
            }
            if(i-1 == 0){
                result += letVal[findIndx(s[0])];
            }
        }
        return result;
    }
};