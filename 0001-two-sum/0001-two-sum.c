int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the return array
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 2; // The return array will always have 2 elements if a solution is found

    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; // Return the indices of the two numbers
            }
        }
    }

    // If no solution is found, adjust returnSize and return NULL
    *returnSize = 0;
    free(result);
    return NULL;
}