class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int over = 0;
        for(int i=0; i<gas.size(); i++) {
            gas[i] = gas[i]-cost[i];
            over += gas[i];
        }
        if(over<0) return -1;
        
        int max_pos = 0;
        int max_start = 0;
        int max_0 = 0;
        
        int temp_start = 0;
        int temp_pos = 0;
        
        for(int i=0; i<gas.size(); i++) {
            temp_pos += gas[i];
            
            if(temp_pos>max_pos) {
                max_pos = temp_pos;
                max_start = temp_start;
            }
            else if(temp_pos<0) {
                temp_start = i+1;
                temp_pos = 0;
                if(max_start==0) max_0 = max_pos;
            }
        }
        
        int i=0;
        while(i<temp_start) {
            temp_pos += gas[i];
            
            if(temp_pos>max_pos) {
                max_pos = temp_pos;
                max_start = temp_start;
            }
            else if(temp_pos<0) {
                break;
            }
            
            i++;
        }
        
        return max_start;
    }
};
