class Solution {
public:
    int trap(vector<int>& height) {
    vector<int> left(height.size());
    vector<int> right(height.size());


     int sum=0;

     left[0] = height[0];
     for(int i=1; i<height.size(); i++){
        left[i] = max(left[i-1], height[i]);
     }   

     right[height.size() - 1] = height[height.size() - 1];
     for(int i=height.size()-2; i>=0; i--){
        right[i] = max(right[i+1], height[i]);
     } 

    for(int i=0 ; i<height.size()  ;i++){
        int ss = min(left[i], right[i]) - height[i];
        if(ss > 0)
            sum+=ss;
    }
    return sum;

    }
};