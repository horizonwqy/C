#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int m = 10, count = 0;
    long long i, tmp, answer, n;
    while (scanf("%lld", &n) != 0)
    {
        for (i = 2;; i++)
        {
            tmp = n * i;
            answer = tmp;
            count = 0;
            m = 10;
            while (tmp)
            {
                if (tmp % 10 != m)
                {
                    count++;
                    m = tmp % 10;
                }
                tmp /= 10;
            }
            if (count == 2)
            {
                printf("%lld:%lld\n", n, answer);
                break;
            }
        }
    }
    return 0;
}