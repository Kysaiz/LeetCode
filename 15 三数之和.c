/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (numsSize < 3)
    {
        return NULL;
    }
    
    int **result = (int**)malloc(sizeof(int*) * (numsSize - 2) * (numsSize - 2));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize - 2) * (numsSize - 2));
    
    // 快排
    qsort(nums, numsSize, sizeof(int), compare);

    int i = 0, j, k;
    while (nums[i] <= 0 && i < numsSize-2)
    {
        int x = nums[i];
        j = i+1, k = numsSize-1;
        while (j < k)
        {
            int left = nums[j], right = nums[k];
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                while (j < k && nums[j] == left) j++;
            }
            else if (sum > 0)
            {
                while (j < k && nums[k] == right) k--;
            }
            else
            {
                (*returnColumnSizes)[*returnSize] = 3;//记录列数
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[(*returnSize)++][2] = nums[k];
                
                while (j < k && nums[j] == left) j++;
                while (j < k && nums[k] == right) k--;
            }

        }

        while (i < numsSize-2 && x == nums[i]) i++;
    }

    return result;
}