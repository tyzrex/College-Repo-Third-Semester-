#include <stdio.h>
#include <string.h>

int main() {
    char bin[100];
    int len;
    printf("Enter a valid binary number: ");
    scanf("%s", bin);
    len = strlen(bin);
    // 1's complement
    for (int i = 0; i < len; i++) {
        if (bin[i] == '1') {
            bin[i] = '0';
        } else {
            bin[i] = '1';
        }
    }
    printf("1's complement: %s\n", bin);
    return 0;
}
