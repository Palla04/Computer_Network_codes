#include <stdio.h>
#include <string.h>

int main() {
    char binary[100];
    int i, count = 0;
    char parity_choice;

    // Input the received binary number with parity bit
    printf("Enter the received binary number with parity bit: ");
    scanf("%s", binary);

    // Ask the user for parity type
    printf("Choose parity - even (e) or odd (o): ");
    scanf(" %c", &parity_choice);

    // Count number of 1s in the binary string
    for (i = 0; i < strlen(binary); i++) {
        if (binary[i] == '1') {
            count++;
        }
    }

    // Check parity
    if (parity_choice == 'e') {
        // Even parity
        if (count % 2 == 0) {
            printf("No error detected.\n");
        } else {
            printf("Error detected.\n");
        }
    } else if (parity_choice == 'o') {
        // Odd parity
        if (count % 2 != 0) {
            printf("No error detected.\n");
        } else {
            printf("Error detected.\n");
        }
    } else {
        printf("Invalid parity choice!\n");
        return 1;
    }

    return 0;
}
