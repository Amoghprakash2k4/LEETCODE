
char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len = strlen(s);
    char** rows = (char**)malloc(sizeof(char*) * numRows);
    for (int i = 0; i < numRows; i++) {
        rows[i] = (char*)calloc(len + 1, sizeof(char));  // Allocate memory for each row
    }
    int currentRow = 0;
    int goingDown = 0;
    for (int i = 0; i < len; i++) {
        strncat(rows[currentRow], &s[i], 1);
        if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
        currentRow += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[0] = '\0';  // Initialize result string

    for (int i = 0; i < numRows; i++) {
        strcat(result, rows[i]);
        free(rows[i]);  // Free each row's allocated memory
    }
    free(rows);  // Free the rows array

    return result;
}