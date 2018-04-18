class Solution {
public:
    int maxArea(vector<int>& height) {
        int MA=0;
        int front = 0, back = height.size()-1;
        while(back>front){
            int area = (back-front)*(height[back]<height[front]?height[back]:height[front]);
            if(area>MA) MA = area;
            
            if(height[back]<height[front]) back--;
            else front++;
        }
        
        return MA;
    }
};
