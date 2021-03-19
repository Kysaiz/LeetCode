/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *a = malloc(2 * sizeof(int));
    
    // for (int i = 0; i < numsSize-1; i++)
    //     for (int j = 0; j < numsSize; j++)
    //     {
    //         if (nums[i] > nums[j])
    //         {
    //             int t = nums[i];
    //             nums[i] = nums[j];
    //             nums[j] = t;
    //         }
    //     }
    
    for (a[0] = 0; a[0] < numsSize - 1; a[0]++)
    {
        for (a[1] = a[0] + 1; a[1] < numsSize; a[1]++)
        {
            if (nums[a[0]] + nums[a[1]] == target)
            {
                *returnSize = 2;
                return a;
            }
        }
    }
    return NULL;
}