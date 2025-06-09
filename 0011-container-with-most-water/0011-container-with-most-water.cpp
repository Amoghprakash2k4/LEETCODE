class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size() - 1;
        int h=0;
        int max=0;
        while(left <= right){
            h=(height[right] < height[left]) ? height[right] : height[left];
            int width =  right - left;
            int area = width * h;
            if(area > max){
                max= area;
            }
            if(height[right] < height[left]){
                right--;
            }
            else{
                left++;
            }
        }
        return max;
    }
};