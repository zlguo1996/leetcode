class Solution {
public:
struct SubStr{
    int word_num;
    map<string, int> words_list;
    map<string, int> wl_buffer;
    vector<string> wo_buffer;
    
    void initMap(vector<string>& words){
        for(int i=0; i<words.size(); i++){
            auto it = words_list.find(words[i]);
            if (it==words_list.end()) {
                words_list.insert(pair<string, int>(words[i], 1));
            }else{
                words_list[words[i]]++;
            }
        }
        
        word_num = words.size();
        
        for(map<string, int>::iterator iter=words_list.begin(); iter!=words_list.end(); iter++){
            wl_buffer.insert(pair<string, int>(iter->first, 0));
        }
    }
    
    bool isWord(string& s){
        return words_list.count(s);
    }
    
    bool isFull(){
        return wo_buffer.size()==word_num;
    }
    
    bool insert(string s){
        if(words_list[s]>wl_buffer[s]){
            wl_buffer[s]++;
            wo_buffer.push_back(s);
        }
        else if(words_list[s]==wl_buffer[s]){
            wl_buffer[s]++;
            wo_buffer.push_back(s);
            
            deleteToDuplicate(s);
        }
        
        if(isFull()) return true;
        else return false;
    }
    
    void clearBuffer(){
        for(map<string, int>::iterator iter=wl_buffer.begin(); iter!=wl_buffer.end(); iter++){
            iter->second = 0;
        }
        wo_buffer.clear();
    }
    
    void deleteToDuplicate(string& s){
        while(wo_buffer[0]!=s){
            wl_buffer[wo_buffer[0]]--;
            wo_buffer.erase(wo_buffer.begin());
        }
        wl_buffer[wo_buffer[0]]--;
        wo_buffer.erase(wo_buffer.begin());
    }
};

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    
    if (s.length()==0 || words.empty()) {
        return res;
    }
    
    SubStr ss;
    ss.initMap(words);
    
    int ws = (int)words[0].size();
    for(int i=0; i<ws; i++){
        int ind_front = i;
        while(ind_front<=(int)s.size()-ws*ss.word_num){
            int ind_present = ind_front;
            while (ind_present<=(int)s.size()-ws) {
                string substr = s.substr(ind_present, ws);
                if(!ss.isWord(substr)){
                    ss.clearBuffer();
                    ind_front = ind_present + ws;
                    break;
                }
                
                bool flag = ss.insert(substr);
                ind_front = ind_present-((int)ss.wo_buffer.size()-1)*ws;
                if(flag) res.push_back(ind_front);
                    
                ind_present += ws;
                if (ind_present>(int)s.size()-ws) {
                    ind_front += ws;
                    ss.clearBuffer();
                }
            }
        }
    }
    
    return res;
}
};
