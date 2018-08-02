class Solution {
public:
    string justifyLastLine(vector<string>& words, int maxWidth){
        string last_line = words[0];
        for (int i=1; i<words.size(); i++) {
            last_line += ' ';
            last_line += words[i];
        }
        if(last_line.size()<maxWidth){
            last_line += string(maxWidth-last_line.size(), ' ');
        }
        return last_line;
    }
    string justifyOneLine(vector<string>& words, int maxWidth){
        int totalLength = 0;
        for (auto word : words) totalLength += word.size();
        int wordNum = words.size();
        if(wordNum==1) return justifyLastLine(words, maxWidth);
        int differ = maxWidth-totalLength;
        int evenSpace = differ/(wordNum-1);
        int remainder = differ%(wordNum-1);
        
        string res = words[0];
        for (int i=1; i<words.size(); i++) {
            res += string(evenSpace, ' ');
            if(i<=remainder) res += ' ';
            res += words[i];
        }
        
        return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        
        int line_width = 0;
        vector<string> line;
        for (int i=0; i<words.size(); i++) {
            if(line_width+words[i].size()<=maxWidth) {
                line_width+=words[i].size()+1;
                line.push_back(words[i]);
            }
            else{
                res.push_back(justifyOneLine(line, maxWidth));
                line.clear();
                
                line_width = words[i].size()+1;
                line.push_back(words[i]);
            }
        }
        if (!line.empty()) res.push_back(justifyLastLine(line, maxWidth));
        
        return res;
    }
};
