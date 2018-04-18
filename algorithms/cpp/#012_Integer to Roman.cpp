class Solution {
public:
    string intToRoman(int num) {
        string s;
        
        char symbol_1[7] = {
            'I', 'X', 'C', 'M'
        };
        int value_1[7] = {
            1, 10, 100, 1000
        };
        char symbol_2[7] = {
            'V', 'L', 'D'
        };
        int value_2[7] = {
            5, 50, 500
        };
        
        for(int i=3; i>=0; i--){
            int c_num = num/value_1[i];
            if(c_num==9){
                s += symbol_1[i];
                s += symbol_1[i+1];
            }
            else if(c_num==4){
                s += symbol_1[i];
                s += symbol_2[i];
            }
            else {
                if(c_num>=5){
                    c_num -= 5;
                    s += symbol_2[i];
                }
                while(c_num>0){
                    s += symbol_1[i];
                    c_num--;
                }
            }
            num = num%value_1[i];
        }
        
        return s;
    }
};
