#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "json.h"

int readStream(char source[], char *fileName)
{
  int chRead = 0;
  FILE *file = fopen(fileName, "r");
  if(file == NULL) return -1;

  while (!feof(file)) {
	char c = fgetc(file);
	if (!feof(file)) source[chRead++] = c;
  }

  return chRead;
}

int isOperator(char a)
{
  if(a == ',') return 1;
  else if(a == ' ') return 1;
  else if(a == '.') return 1;
  else return 0;
}

int tokenize(char *stream, char *tokens, int length)
{
  int fpos = 0, tpos = 0;
  int size = length;

  for(int i = 0; i < size; i++){
	//Verifica operador de divisao de valor
	if(stream[fpos] == ':'){
	  while(stream[fpos] != ','){

		if(isOperator(stream[fpos])){
		  tokens[tpos] = stream[fpos];
		  tpos++; fpos++;
		}

		if(isalpha(stream[fpos])){
		  while(isalpha(stream[fpos])){
			tokens[tpos] = stream[fpos];
			tpos++; fpos++;

			if(isOperator(stream[fpos])){
			  tokens[tpos] = stream[fpos];
			  tpos++; fpos++;
			}
			
			if(stream[fpos] == '\0'){
			  tokens[tpos] = '\0';
			}
		  }
		}

		if(isdigit(stream[fpos])){
		  while(isdigit(stream[fpos])){
			tokens[tpos] = stream[fpos];
			tpos++; fpos++;

			if(isalpha(stream[fpos])){
			  tokens[tpos] = stream[fpos];
			  tpos++; fpos++;
			}

			if(isOperator(stream[fpos])){
			  tokens[tpos] = stream[fpos];
			  tpos++; fpos++;
			}

			if(stream[fpos] == '\0'){
			  tokens[tpos] = '\0';
			}
		  }
		}

		if((stream[fpos] == '.') && (isdigit(stream[fpos+1]))){
		  tokens[tpos] = stream[fpos];
		  tpos++; fpos++;
		  while(isdigit(stream[fpos])){
			tokens[tpos] = stream[fpos];
			tpos++; fpos++;
			
			if(isOperator(stream[fpos])){
			  tokens[tpos] = stream[fpos];
			  tpos++; fpos++;
			}

			if(stream[fpos] == '\0'){
			  tokens[tpos] = '\0';
			}
		  }
		}

		if(stream[fpos] == '}'){
		  tokens[tpos] = '\0';
		  return tpos;
		}
		
		fpos++;
	  }

	}else if(stream[fpos] == ','){
	  tokens[tpos] = ',';
	  tpos++; fpos++;
	}
	else fpos++;
  }

  return -1;
}

void printTokens(char *tokenList, int count)
{
  int t;
  printf("TokenList:\n\n");
  for(t = 0; t < count; t++){
	printf("%c", tokenList[t]);
	if(tokenList[t] == ',')printf("\n");
  }
}
