#include <stdio.h>

int main() {
    int a[10], b[10], sum[10], chk[10], chks[10], carry = 0, n, i, p;

    printf("------ Checksum Sender Program ------\n");
    printf("Enter the number of bits of each segment: ");
    scanf("%d", &n);

    printf("\nEnter the first segment (%d bits one after another): ", n);
    for (i = n - 1; i >= 0; i--) {
        scanf("%d", &a[i]);
    }

    printf("Enter the second segment: ");
    for (i = n - 1; i >= 0; i--) {
        scanf("%d", &b[i]);
    }

    // Calculate initial sum with carry handling
    for (i = 0; i < n; i++) {
        sum[i] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }

    printf("\nInitial Sum: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }

    // If carry is present, wrap the sum
    if (carry == 1) {
        for (i = 0; i < n; i++) {
            p = (sum[i] + carry) % 2;
            carry = (sum[i] + carry) / 2;
            sum[i] = p;
        }
    }

    printf("\nWrapped Sum: ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }

    // Calculate checksum by inverting the wrapped sum
    printf("\nChecksum: ");
    for (i = n - 1; i >= 0; i--) {
        if (sum[i] == 1)
            chks[i] = 0;
        else
            chks[i] = 1;
        printf("%d", chks[i]);
    }
    printf("\n");

    return 0;
}