
char* intToRoman(int num) {
    // Define arrays of Roman numerals and their corresponding integer values
    const char* roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Allocate enough space for the resulting Roman numeral string
    // The maximum length for a Roman numeral under 4000 is 15 characters
    char* result = (char*)malloc(16);
    result[0] = '\0'; // Initialize the string to be empty

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, roman[i]);
            num -= values[i];
        }
    }

    return result;
}