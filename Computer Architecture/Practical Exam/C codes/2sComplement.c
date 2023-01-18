#include <stdio.h>
#include <string.h>

int main() {
    char bin[100];
    int len;

    printf("Enter a valid binary number: ");
    scanf("%s", bin);
    len = strlen(bin);

    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            bin[i] = '0';
        } else {
            bin[i] = '1';
        }
    }

    int carry = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (bin[i] == '1' && carry == 1) {
            bin[i] = '0';
        } else if (bin[i] == '0' && carry == 1) {
            bin[i] = '1';
            carry = 0;
        }
    }

    printf("2's complement: %s\n", bin);
    return 0;
}
