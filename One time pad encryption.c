#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char message[100], key[100], cipher[100];
    int i, message_len, key_len;

    // Get message input from user
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get key input from user
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from message and key
    message_len = strlen(message) - 1;
    message[message_len] = '\0';
    key_len = strlen(key) - 1;
    key[key_len] = '\0';

    // Check if key is long enough
    if (key_len < message_len) {
        printf("Error: Key is too short.\n");
        return 1;
    }

    // Generate random seed for key stream
    srand(time(NULL));

    // Generate key stream
    for (i = 0; i < message_len; i++) {
        int random_number = rand() % 26;
        key[i] = 'A' + random_number;
    }
    key[message_len] = '\0';

    // Encrypt message using key stream
    for (i = 0; i < message_len; i++) {
        cipher[i] = ((message[i] - 'A') + (key[i] - 'A')) % 26 + 'A';
    }
    cipher[message_len] = '\0';

    printf("Plaintext: %s\n", message);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", cipher);

    return 0;
}
