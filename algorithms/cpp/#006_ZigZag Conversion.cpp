class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        
        int s_len = s.length();
        int block_size = numRows*2-2;
        
        int block_num = s_len/block_size;
        int residual_num = s_len%block_size;
        
        string result = "";
        for(int r=0; r<numRows; r++){
            for(int b=0; b<block_num; b++){
                result += s[b*block_size+r];
                if(r>0&&r<numRows-1){
                    result += s[(b+1)*block_size-r];
                }
            }
            if(block_num*block_size+r<s_len) result += s[block_num*block_size+r];
            if(r>0&&r<numRows-1&&(block_num+1)*block_size-r<s_len) result += s[(block_num+1)*block_size-r];
        }
        
        return result;
    }
};
