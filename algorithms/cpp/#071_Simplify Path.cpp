class Solution {
public:
    size_t findLastSlash(string path, size_t pos){
        size_t res = pos;
        while (res>0) {
            res--;
            if(path[res]=='/') return res;
        }
        return pos;
    }
    string simplifyPath(string path) {
        size_t found = path.find("//", 0);
        while (found!=string::npos) {
            path.replace(found, 2, "/");
            found = path.find("//", found);
        }
        
        found = path.find("/.", 0);
        while(found!=string::npos){
            if(found+2<path.size()&&path[found+2]=='.'){
                if(found+3<path.size()&&path[found+3]!='/') {
                    found = path.find("/.", found+3);
                    continue;
                }
                size_t pos_slash = findLastSlash(path, found);
                path.replace(pos_slash, found-pos_slash+3, "");
                found = path.find("/.", pos_slash);
            }
            else{
                if(found+2<path.size()&&path[found+2]!='/') {
                    found = path.find("/.", found+2);
                    continue;
                }
                path.replace(found, 2, "");
                found = path.find("/.",found);
            }
        }
        
        if(path.size()>1 && path[path.size()-1]=='/') path.replace(path.size()-1, 1, "");
        
        if(path.size()==0) path += '/';
        
        return path;
    }
};
