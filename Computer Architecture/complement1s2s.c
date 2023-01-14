#include <stdio.h>
#include <string.h>

// Function to calculate 1's complement of a binary number
void onesComplement(char bin[], char ones_comp[]) {
    int len = strlen(bin);
    for (int i = 0; i < len; i++) {
        if (bin[i] == '0')
            ones_comp[i] = '1';
        else
            ones_comp[i] = '0';
    }
    ones_comp[len] = '\0';
}

// Function to calculate 2's complement of a binary number
void twosComplement(char bin[], char twos_comp[]) {
    char ones_comp[32];
    onesComplement(bin, ones_comp);
    int i = strlen(ones_comp) - 1;
    twos_comp[i] = ones_comp[i] == '0' ? '1' : '0';
    i--;
    while (i >= 0 && ones_comp[i] == '1') {
        twos_comp[i] = '0';
        i--;
    }
    if (i >= 0)
        twos_comp[i] = '1';
    twos_comp[strlen(ones_comp)] = '\0';
}

int main() {
    char bin[32];
    printf("Enter a binary number: ");
    scanf("%s", bin);

    char ones_comp[32];
    onesComplement(bin, ones_comp);
    printf("1's complement: %s\n", ones_comp);

    char twos_comp[32];
    twosComplement(bin, twos_comp);
    printf("2's complement: %s\n", twos_comp);

    return 0;
}
