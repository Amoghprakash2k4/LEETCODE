bool isPalindrome(int x) {
    // Negative numbers cannot be palindromes
    if (x < 0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    while (x != 0) {
        int digit = x % 10;

        // Check for overflow before updating the reversed number
        if (reversed > (INT_MAX - digit) / 10) {
            // This means reversing would cause an overflow
            return false;
        }

        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}