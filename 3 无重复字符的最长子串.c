int lengthOfLongestSubstring(char * s)
{
    int start = 0;
    int end = 0;
    int t = 0;
    int max = 0;

    while (end < strlen(s))
    {
        char c = s[end];
        for (int i = start; i < end; i++)
        {
            if (c == s[i])
            {
                start = i + 1;
                t = end - start;
                break;
            }
        }

        end++;
        t++;
        max = max > t ? max : t;
    }

    return max;
}