int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int myabs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    
    return x;
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (numsSize < 3)
    {
        return 0;
    }
    
    // 快排
    qsort(nums, numsSize, sizeof(int), compare);
    int ret = nums[0]+nums[1]+nums[2];
    
    int i = 0, j, k;
    while (i < numsSize-2)
    {
        int x = nums[i];
        j = i+1, k = numsSize-1;
        while (j < k)
        {
            int left = nums[j], right = nums[k];
            int sum = nums[i] + nums[j] + nums[k];
            if (myabs(sum-target) < myabs(ret-target))
            {
                ret = sum;
            }
            
            if (sum < target)
            {
                while (j < k && nums[j] == left) j++;
            }
            else if (sum > target)
            {
                while (j < k && nums[k] == right) k--;
            }
            else
            {
                return target;
            }

        }

        while (i < numsSize-2 && x == nums[i]) i++;
    }
        
    return ret;
}