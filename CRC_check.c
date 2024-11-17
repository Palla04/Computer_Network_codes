#include <stdio.h>

int main()
{
    int m1[20], d[10], rem1[10], i, j, k, len, divlen;

    printf("\nEnter the length of divisor\n");
    scanf("%d", &divlen);
    printf("\nEnter the divisor:\n");
    for (i = 0; i < divlen; i++)
    {
        scanf("%d", &d[i]);
    }
    
    printf("\nEnter the length of received data (data + CRC)\n");
    scanf("%d", &len);
    printf("\nEnter the received data + CRC:\n");
    for (i = 0; i < len; i++)
    {
        scanf("%d", &m1[i]);
    }

    // XOR operation to check correctness
    for (i = 0; i < len - divlen + 1; i++)
    {
        if (m1[i] == 1)
        {
            for (j = 0; j < divlen; j++)
            {
                rem1[j] = m1[i + j] ^ d[j];
            }
            for (k = 0; k < divlen; k++)
            {
                m1[i + k] = rem1[k];
            }
        }
        else
        {
            for (k = 0; k < divlen; k++)
            {
                rem1[k] = m1[i + k];
            }
        }
    }

    printf("\nCRC = ");
    j = 0;
    for (i = 1; i < divlen; i++)
    {
        printf("%d", rem1[i]);
        j += rem1[i];
    }

    if (j == 0)
    {
        printf("\nNo error detected\n");
    }
    else
    {
        printf("\nError detected\n");
    }

    return 0;
}
