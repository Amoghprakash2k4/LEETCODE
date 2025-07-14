class Solution {
public:
    int minBitFlips(int start, int goal) {
        // return __builtin_popcount(start ^ goal);
        int xor_gen = start ^ goal;
        int count = 0;
        while(xor_gen){
            count += xor_gen &1;
            xor_gen >>= 1;
        }
        return count;
    }
};

