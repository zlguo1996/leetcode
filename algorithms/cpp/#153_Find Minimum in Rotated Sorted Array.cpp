class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> co_pre;
        co_pre.resize(numCourses);
        for(auto requisite:prerequisites){
            int c = requisite->first;
            int cp = requisite->second;
            co_pre.find(co_pre.begin(), co_pre.end())
        }
    }
};
