#include <stdio.h>

int main()
{
    int m[20], p[20], d[10], i, j, k, len, rem[10], divlen;

    printf("\nEnter the length of divisor\n");
    scanf("%d", &divlen);
    printf("\nEnter the divisor:\n");
    for (i = 0; i < divlen; i++)
    {
        scanf("%d", &d[i]);
    }
    
    printf("\nEnter the length of data\n");
    scanf("%d", &len);
    printf("\nEnter the data:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &m[i]);
        p[i] = m[i];
    }
    
    // Append zeros to the data
    for (i = len; i < len + (divlen - 1); i++)
    {
        m[i] = 0;
    }
    
    printf("\nThe appended value is: ");
    for (i = 0; i < len + (divlen - 1); i++)
    {
        printf("%d", m[i]);
    }

    // XOR operation
    for (i = 0; i < len; i++)
    {
        if (m[i] == 1)
        {
            for (j = 0; j < divlen; j++)
            {
                rem[j] = m[i + j] ^ d[j];
            }
            for (k = 0; k < divlen; k++)
            {
                m[i + k] = rem[k];
            }
        }
        else
        {
            for (k = 0; k < divlen; k++)
            {
                rem[k] = m[i + k];
            }
        }
    }

    printf("\nCRC = ");
    for (i = 1; i < divlen; i++)
    {
        printf("%d", rem[i]);
    }
    printf("\n");

    return 0;
}
