class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        map<int, int> height_map;
        if(heights.size()==0) return 0;
        int max_rec = heights[0];
        height_map[heights[0]] = 0;
        
        for (int i=1; i<heights.size(); i++) {
            if(heights[i]<heights[i-1]){
                pair<map<int, int>::iterator, map<int, int>::iterator> er = height_map.equal_range(heights[i]);
                height_map[heights[i]] = er.first->second;
                for(map<int, int>::iterator it=er.second; it!=height_map.end(); it++){
                    int tmp_rec = it->first*(i-it->second);
                    if(tmp_rec>max_rec) max_rec = tmp_rec;
                }
                height_map.erase(er.second, height_map.end());
            }
            else if (heights[i]==heights[i-1]) continue;
            else {
                height_map.insert(pair<int, int>(heights[i], i));
            }
        }
        
        for(map<int, int>::iterator it=height_map.begin(); it!=height_map.end(); it++){
            int tmp_rec = it->first*(heights.size()-it->second);
            if(tmp_rec>max_rec) max_rec = tmp_rec;
        }
        
        return max_rec;
    }
};
