#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char cipher[100], key[100], message[100];
    int i, cipher_len, key_len;

    // Get ciphertext input from user
    printf("Enter ciphertext to decrypt: ");
    fgets(cipher, sizeof(cipher), stdin);

    // Get key input from user
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from ciphertext and key
    cipher_len = strlen(cipher) - 1;
    cipher[cipher_len] = '\0';
    key_len = strlen(key) - 1;
    key[key_len] = '\0';

    // Check if key is long enough
    if (key_len < cipher_len) {
        printf("Error: Key is too short.\n");
        return 1;
    }

    // Decrypt ciphertext using key
    for (i = 0; i < cipher_len; i++) {
        message[i] = ((cipher[i] - 'A') - (key[i] - 'A') + 26) % 26 + 'A';
    }
    message[cipher_len] = '\0';

    printf("Ciphertext: %s\n", cipher);
    printf("Key: %s\n", key);
    printf("Plaintext: %s\n", message);

    return 0;
}
