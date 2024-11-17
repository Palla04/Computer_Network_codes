#include <stdio.h>

int main() {
    int a[10], b[10], chks[10], sum[10], wrapped_sum[10], n, i, carry = 0, temp = 0, p;

    printf("------ Checksum Receiver Program ------\n");
    printf("Enter the number of bits of each segment: ");
    scanf("%d", &n);

    // Input the two data segments
    printf("\nEnter the received data segment (%d bits one after another): ", n);
    for (i = n - 1; i >= 0; i--) {
        scanf("%d", &a[i]);
    }

    printf("Enter the second segment (next %d bits one after another): ", n);
    for (i = n - 1; i >= 0; i--) {
        scanf("%d", &b[i]);
    }

    // Input the received checksum
    printf("Enter the received checksum: ");
    for (i = n - 1; i >= 0; i--) {
        scanf("%d", &chks[i]);
    }

    // Step 1: Add the two data segments and checksum (initial sum)
    for (i = 0; i < n; i++) {
        sum[i] = (a[i] + b[i] + chks[i] + carry) % 2;
        carry = (a[i] + b[i] + chks[i] + carry) / 2;  // Properly calculate the carry
    }
    
    printf("\nInitial sum (data segments + checksum): ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d", sum[i]);
    }

    // Step 2: If there's a carry, wrap it around (add 1 to the sum)
    if (carry == 1) {
        for (i = 0; i < n; i++) {
            p = (sum[i] + carry) % 2;
            carry = (sum[i] + carry) / 2;
            sum[i] = p;
        }
    }

    // Wrapped sum result
    printf("\nWrapped sum: ");
    for (i = n - 1; i >= 0; i--) {
        wrapped_sum[i] = sum[i];
        printf("%d", wrapped_sum[i]);
    }

    // Step 3: Take the 1's complement of the wrapped sum
    printf("\nFinal Checksum (1's complement of wrapped sum): ");
    for (i = 0; i < n; i++) {
        wrapped_sum[i] = wrapped_sum[i] == 1 ? 0 : 1;  // 1's complement of wrapped sum
        temp += wrapped_sum[i];  // This is to check the final checksum
        printf("%d", wrapped_sum[i]);
    }

    // If the final checksum is all 0s, data is valid
    if (temp == 0) {
        printf("\nChecksum PASSED.\n");
    } else {
        printf("\nChecksum FAILED, Received data is Corrupted.\n");
    }

    return 0;
}