/*
 * File:        main.c
 * Author:      Hasan Zahid
 * Description: This is the main entry point for the Ghost Comm, a console-based interface
 *              to convert alphanumeric text to Morse code.
 *              Components:
 *                  - clearBuffer(): clear the buffer after every input
 *                  - main(): handles user interaction, input selection, and calls
 *                            appropriate encoding and decoding logic.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ghostComm.h"

void clearBuffer(void){
    char input;
    while((input = getchar())!= '\n' && input != EOF);
}

int main() {
    // store the user option
    int option;
    // size of input characters
    char text[2000];

    // options for the user to choose from
    printf("=== Ghost Comm ===\n");
    printf("1. Encode text to Morse\n");
    printf("2. Decode Morse to text\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    clearBuffer();

    // condition to run the option selected by the user.
    if (option == 1) {
        printf("Enter text to encode:\n");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;

        // call the 'encodeToMorse' function and store it
        // in the variable 'encoded'.
        char *encoded = encodeToMorse(text);
        printf("Encoded Morse: %s\n", encoded);
        // free the memory
        free(encoded);

    } else if (option == 2) {
        printf("Enter Morse Code to decode:\n");
        fgets(text, sizeof(text), stdin);
        text[strcspn(text, "\n")] = 0;

        // call the 'decodeFromMorse' function and store it
        // in the variable 'decoded'.
        char *decoded = decodeFromMorse(text);
        printf("Decoded Morse: %s\n", decoded);
        // free the memory
        free(decoded);

    } else {
        printf("Invalid option.\n");
    }

    return 0;
}