/* This program aims to separate the values ​​of a json */

/* Copyright (C) 2024  Samuel Henrique */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256
#define MAX_TOKENS 256

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

int main(int argc, char *argv[])
{
  char tokens[MAX_TOKENS], stream[MAX_CHARS];
  char *ptrTokens = tokens;
  char *ptrStream = stream;
  int i, len;

  if(argc < 2){
	printf("Nenhum parâmetro foi passado\n");
	return 1;
  }
  
  len = readStream(stream, argv[1]);
  if(len == -1) printf("Erro ao ler o stream\n");
  else if(len > MAX_CHARS) printf("Arquivo muito grande, char máx: %i\n\n", MAX_CHARS);
  else printf("Arquivo lido com sucesso, quantidade de caracters do json: %d\n\n", len);
  
  i = tokenize(ptrStream, ptrTokens, len);
  if(i > 1) printf("Tokenizado com sucesso!\nQuantidade de carateres dos tokens: %d\n\n", i);
  else printf("Erro ao tokenizar arquivo!\n");

  printTokens(ptrTokens, i);
  
  return 0;
}
