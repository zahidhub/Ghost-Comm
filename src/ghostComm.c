/*
 * File:        ghostComm.c
 * Author:      Hasan Zahid
 * Description: This module provides functionality to encode plain alphanumeric text into Morse code.
 *              Components:
 *                  - morseCode[]: Array holds Morse code representations alphanumericChar.
 *                  - alphanumericChar[]: Alphanumeric characters (A-Z, 0-9) used for matching with
 *                                        the morse code representation.
 *                  - encodeToMorse(char *text): Encodes the text into morse code.
 *                  - decodeFromMorse(char *morseCodeText): Decodes the morse code to text.
 * License:     MIT (see LICENSE file in the repo)
 * Referances:  https://students.cs.ucl.ac.uk/schoolslab/projects/PY2/introduction.html
 *              https://www.geeksforgeeks.org/morse-code-implementation/
 *              https://stackoverflow.com/questions/28045172/morse-code-converter-in-c
 *              https://gist.github.com/mianbilal10/4023baa141e66b1ff20d14de93c7b8a6
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
 * are represented by '/' in the 'encodedCode'. Returns a dynamically allocated string
 * that contains the encoded morse code.
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

/* Takes a string of morse code and converts it back to the human readable text.
 * Each morse code character is separated by a space, and words are separated by '/'.
 * It uses goes through the arrays morseCode[] and alphanumericChar[] to find the match.
 * Returns a dynamically allocated string that contains the decoded readable text.
 */
char *decodeFromMorse(char *morseCodeText) {

    // allocate memory for decodedText
    char *decodedText = malloc(5000);
    // index for decodedText
    int decodedTextIndex = 0;

    // buffer to hold each morse code represantation
    char morseSymbolBuffer[6];
    int bufferIndex = 0;

    for (int i = 0; morseCodeText[i] != '\0'; i++) {
        // if space is encountered a morse code character has ended
        if (morseCodeText[i] == ' ') {
            // terminate the Morse symbol
            morseSymbolBuffer[bufferIndex] = '\0';

            // check if it is a word separator and add space 
            if (strcmp(morseSymbolBuffer, "/") == 0) {
                decodedText[decodedTextIndex++] = ' ';
            } else {
                // go through the morse code in morseCode[] to find the matching character
                for (int j = 0; j < 36; j++) {
                    if (strcmp(morseSymbolBuffer, morseCode[j]) == 0) {
                        decodedText[decodedTextIndex++] = alphanumericChar[j];
                        break;
                    }
                }
            }
            // reset buffer for next morse code
            bufferIndex = 0;  
        } else {
            // store the morse represantation into buffer
            morseSymbolBuffer[bufferIndex++] = morseCodeText[i];
        }
    }

    // handle last morse represantation
    if (bufferIndex > 0) {
        morseSymbolBuffer[bufferIndex] = '\0';
        for (int j = 0; j < 36; j++) {
            if (strcmp(morseSymbolBuffer, morseCode[j]) == 0) {
                decodedText[decodedTextIndex++] = alphanumericChar[j];
                break;
            }
        }
    }

    // terminate the decoded string
    decodedText[decodedTextIndex] = '\0';
    return decodedText;
}