
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return ""; // If the array is empty, return an empty string
    
    // Use the first string as the initial prefix
    char* prefix = strs[0];
    int prefixLength = strlen(prefix);
    
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // Compare the current string with the prefix character by character
        while (j < prefixLength && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        // Update the prefix length based on the common prefix length with the current string
        prefixLength = j;
        
        // If at any point the prefix becomes empty, return an empty string
        if (prefixLength == 0) {
            return "";
        }
    }
    
    // Create a new string to hold the common prefix
    char* result = (char*)malloc(prefixLength + 1);
    strncpy(result, prefix, prefixLength);
    result[prefixLength] = '\0'; // Null-terminate the string
    
    return result;
}