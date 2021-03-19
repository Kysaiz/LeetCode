/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void myfunc(int i, int n, int left, int right, char s[], char ***result, int *p)
{
    if (i == n*2)
    {
        s[i] = '\0';
        *result = (char**)realloc(*result, sizeof(char*)*(*p+1));
        result[0][*p] = (char*)malloc(n*2+1);
        memcpy(result[0][*p], s, n*2+1);
        (*p)++;
    }
    else
    {
        if (left < n)
        {
            s[i] = '(';
            myfunc(i+1, n, left+1, right, s, result, p);
        }
        
        if (right < n && right < left)
        {
            s[i] = ')';
            myfunc(i+1, n, left, right+1, s, result, p);
        }
    }
}

char ** generateParenthesis(int n, int* returnSize)
{
    *returnSize = 0;
    char *s = malloc(n*2+1);
    char **result = NULL;
    myfunc(0, n, 0, 0, s, &result, returnSize);
    
    return result;
}