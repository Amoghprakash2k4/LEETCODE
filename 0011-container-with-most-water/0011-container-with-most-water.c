
int maxArea(int* height, int heightSize) {
    int max = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        // Calculate the area between the lines at positions left and right
        int h = (height[left] < height[right]) ? height[left] : height[right];
        int width = right - left;
        int area = h * width;
        
        // Update the maximum area found
        if (area > max) {
            max = area;
        }
        
        // Move the pointer of the shorter line towards the center
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max;
}