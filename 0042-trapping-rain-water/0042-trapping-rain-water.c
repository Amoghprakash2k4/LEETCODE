#define min(x, y) (((x) < (y)) ? (x) : (y))

int trap(int *height, int heightSize) {
    if (heightSize == 0) return 0; 
    
    int left[heightSize];
    int right[heightSize];
    int max = 0;
    int units = 0;

    left[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        left[i] = (height[i] > left[i - 1]) ? height[i] : left[i - 1];
    }
    right[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        right[i] = (height[i] > right[i + 1]) ? height[i] : right[i + 1];
    }
    for (int i = 0; i < heightSize; i++) {
        max = min(left[i], right[i]) - height[i];
        if (max > 0) { 
            units += max;
        }
    }

    return units;
}