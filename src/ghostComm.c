/*
 * File:        ghostComm.c
 * Author:      Hasan Zahid
 * Description: This module provides functionality to encode plain alphanumeric text into Morse code.
 *              Components:
 *                  - morseCode[]: Array holds Morse code representations alphanumericChar.
 *                  - alphanumericChar[]: Alphanumeric characters (A-Z, 0-9) used for matching with
 *                                        the morse code representation.
 *                  - encodeToMorse(char *text): Encodes the text into morse code.
 * License:     MIT (see LICENSE file in the repo)
 * Referances:  https://students.cs.ucl.ac.uk/schoolslab/projects/PY2/introduction.html
 *              https://www.geeksforgeeks.org/morse-code-implementation/
 *              https://stackoverflow.com/questions/28045172/morse-code-converter-in-c
 *              https://www.geeksforgeeks.org/how-do-i-create-a-library-in-c/
 *              https://stackoverflow.com/questions/30033582/what-is-the-symbol-for-whitespace-in-c
 *              https://www.geeksforgeeks.org/strcat-in-c/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ghostComm.h"

// morse code representation
char *morseCode[36] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", 
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
    ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."                                        
};

// alphanumeric character for morse
char alphanumericChar[36] = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R',
    'S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'
};

/* Takes a string of text then converts each character to uppercase and maps it to the 
 * morse code (morseCode[]) using the lookup arrays. Spaces between words in the input 
 * are represented by '/' in the 'encodedCode'. Returns a dynamically allocated string that contains 
 * the encoded morse code.
 */
char *encodeToMorse(char *text) {

    // allocate memory for encodedCode
    char *encodedCode = malloc(5000);
    // empting the string
    encodedCode[0] = '\0'; 

    for (int i = 0; text[i] != '\0'; i++) {
        // convert all ch to upper case
        char ch = toupper(text[i]);  

        if (ch == ' ') {
            // add '/' in exchange of space (space bar)
            strcat(encodedCode, "/ "); 
            continue;
        }

        for (int j = 0; j < 36; j++) {
            if (alphanumericChar[j] == ch) {
                // appeand the morse code in the variable
                strcat(encodedCode, morseCode[j]);
                // add space after each morse code char
                strcat(encodedCode, " ");           
                break;
            }
        }
    }
    // return the morse code
    return encodedCode;
}
