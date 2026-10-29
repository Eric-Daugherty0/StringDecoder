#ifndef DAUGHERTY_STRINGDECODER_H
#define DAUGHERTY_STRINGDECODER_H

#define MAX_LEN 256
// Function prototypes for the string encoding functions
void encodeString(const char original[], char encoded[], const char chart[]);
int askToRepeat(void);
void readLine(char line[], int size);

#endif
