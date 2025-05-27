class Solution {
public:
    int differenceOfSums(int n, int m) {
        int one=0;
        int two=0;
        for(int i=0 ; i <=n ; i++){
            if(i%m == 0){
                one += i;
            }
            if(i%m != 0){
                two += i;
            }
        
        }
        return two-one;
    }

};