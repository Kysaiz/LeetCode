int strStr(char * haystack, char * needle){
    int len = strlen(needle);
    if (needle == NULL || len == 0)
    {
        return 0;
    }
    else if (len > strlen(haystack))
    {
        return -1;
    }
    int i, j;
    
    for (i = 0; i <= strlen(haystack)-len; i++)
    {
        if (haystack[i] == needle[0]) // 如果首字母相等，进入循环判断
        {
            for (j = 0; j < len; j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if (j == len)
            {
                return i;
            }
        }

    }
    
    return -1;
}