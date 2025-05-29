// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         int original =x;
//         long long rev =0;
//         while(x!=0){
//             int digit= x%10;
//             rev =  rev *10+digit;
//             x/=10;
//         }

//         return rev==original;
//     }
    
// };

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (but not 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversedHalf = 0;
        while (x > reversedHalf) {
            int digit = x % 10;
            reversedHalf = reversedHalf * 10 + digit;
            x /= 10;
        }

        // For even digit count: x == reversedHalf
        // For odd digit count: x == reversedHalf / 10
        return (x == reversedHalf) || (x == reversedHalf / 10);
    }
};
