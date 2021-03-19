double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int i = 0, j = 0, t;
    double mid;
    if ((nums1Size + nums2Size)%2 == 0)
    {
        while (i + j < (nums1Size + nums2Size)/2)
        {
            if (j == nums2Size)
            {
                t = nums1[i];
                i++;
            }
            else if (i == nums1Size)
            {
                t = nums2[j];
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                t = nums2[j];
                j++;
            }
            else
            {
                t = nums1[i];
                i++;
            }
        }

        mid += t;
        if (j == nums2Size)
        {
            t = nums1[i];
        }
        else if (i == nums1Size)
        {
            t = nums2[j];
        }
        else if (nums1[i] > nums2[j])
        {
            t = nums2[j];
        }
        else
        {
            t = nums1[i];
        }
        mid = (mid + t)/2;
    }
    else
    {
        while (i + j < (nums1Size + nums2Size)/2 + 1)
        {
            if (j == nums2Size)
            {
                t = nums1[i];
                i++;
            }
            else if (i == nums1Size)
            {
                t = nums2[j];
                j++;
            }
            else if (nums1[i] > nums2[j])
            {
                t = nums2[j];
                j++;
            }
            else
            {
                t = nums1[i];
                i++;
            }
        }

        mid = t;
    }

    return mid;
}