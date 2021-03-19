int myAtoi(char * s)
{
    // 读走空格
    while (*s == ' ') s++;
    
    // 读取符号，有则设x=-1，无则x=1，最后与结果相乘
    int flag = 1;
    if (*s == '-')
    {
        flag = -1;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }
    
    // 如果第一个字符不是数字，直接返回0
    if (*s < '0' || *s > '9')
    {
        return 0;
    }
    
    // 读取到不是数字或最大长度时停止
    int result = 0, d, i = 0, len = strlen(s);
    for (i = 0; i <= len; i++)
    {
        if (*s < '0' || *s > '9') // 如果不是数字，则停止
        {
            break;
        }
        else if (result >= INT_MAX/10)
        {
            if (*(s+1) < '0' || *(s+1) > '9')
            {
                if (flag == 1)
                {
                    if (result == 214748364)
                    {
                        if(*s - 48 > 6)
                        {
                            return INT_MAX;
                        }
                        else
                        {
                            result *= 10;
                            result += (*s-48);
                            return result;
                        }
                    }
                    else
                    {
                        return INT_MAX;
                    }

                }
                else
                {
                    if (result == 214748364)
                    {
                        if(*s - 48 > 7)
                        {
                            return INT_MIN;
                        }
                        else
                        {
                            result *= 10;
                            result += (*s-48);
                            return result * flag;
                        }
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
            }
            else
            {
                if (flag == 1)
                {
                    return INT_MAX;
                }
                else
                {
                    return INT_MIN;
                }
            }

        }
        else
        {
            result *= 10;
            d = *s - 48;
            s++;
            result += d;
        }
    }
    
    return result * flag;
}