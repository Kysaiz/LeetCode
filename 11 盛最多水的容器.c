int maxArea(int* height, int heightSize)
{
    int l = 0, r = heightSize-1, x = 0, m1 = 0, m2 = 0;
    while (l < r)
    {
        
        if (height[l] > height[r])
        {
            x = height[r] * (r-l) > x ? height[r] * (r-l) : x;
            
            do
            {
                r--;
            }while (m2 > height[r]);
            m2 = height[r];
        }
        else
        {
            x = height[l] * (r-l) > x ? height[l] * (r-l) : x;
            
            do
            {
                l++;
            }while (m1 > height[l]);
            m1 = height[l];
            
        }
        
    }
    
    return x;
}