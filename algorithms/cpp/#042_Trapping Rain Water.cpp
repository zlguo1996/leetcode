class Solution {
public:
int trap(vector<int>& height) {
        int f_front=0, f_back, b_front=height.size()-1, b_back;
        int res=0;
        
        while(f_front<height.size() && height[f_front]==0) f_front++;
        while(b_front>=0 && height[b_front]==0) b_front--;
        
        if(b_front<=0||f_front>=height.size()-1) return res;
        
        f_back = f_front+1;
        b_back = b_front-1;
        
        bool flag = height[f_front]>=height[b_front]?false:true;
        int max_height;
        while (b_back>=f_front&&f_back<=b_front) {
            if (flag) {
                if (height[f_back]<height[f_front]) {
                    res += height[f_front]-height[f_back];
                    f_back++;
                }else{
                    f_front = f_back++;
                    flag = height[f_front]>=height[b_front]?false:true;
                }
            }else{
                if (height[b_back]<height[b_front]) {
                    res += height[b_front]-height[b_back];
                    b_back--;
                }else{
                    b_front = b_back--;
                    flag = height[f_front]>=height[b_front]?false:true;
                }
            }
        }
        
        return res;
    }
};
