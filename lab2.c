#include <stdio.h>
#include <string.h>

int main() {
    int key[2][2], i, j, k;
    char msg[100];
    int len;

    printf("Enter 2x2 key matrix:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    printf("Enter plaintext (lowercase letters only): ");
    scanf("%s", msg);

    len = strlen(msg);

    // If length is odd, add 'x'
    if (len % 2 != 0) {
        msg[len] = 'x';
        msg[len+1] = '\0';
        len++;
    }

    printf("\nEncrypted Text: ");

    for (i = 0; i < len; i += 2) {
        int a = msg[i] - 'a';
        int b = msg[i+1] - 'a';

        int c1 = (key[0][0]*a + key[0][1]*b) % 26;
        int c2 = (key[1][0]*a + key[1][1]*b) % 26;

        printf("%c%c", c1 + 'a', c2 + 'a');
    }

    return 0;
}
