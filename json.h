#ifndef JSON_H
#define JSON_H

#define MAX_CHARS 256
#define MAX_TOKENS 256

void printTokens(char *tokenList, int count);

int readStream(char source[], char *fileName);

int isOperator(char a);

int tokenize(char *stream, char *tokens, int length);

#endif
