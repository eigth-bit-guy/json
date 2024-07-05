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
#include <errno.h>
#include <assert.h>
#include <stdlib.h>
#include "libjson.h"

#define COLUMNS 50

TOK_OBJ_PARSE *new_tok_obj()
{
  return (TOK_OBJ_PARSE*)malloc(sizeof(TOK_OBJ_PARSE));
}

TOK_OBJ_PARSE *alloc_string_array(TOK_OBJ_PARSE *tokens)
{
  const int LINES = 8;
  
  tokens->obj.array = (char**)malloc(LINES * sizeof(char*));
  if(tokens->obj.array == NULL) {
	fprintf(stderr, "error: allocate string array\n");
	exit(1);
  }
  return tokens;
}

TOK_OBJ_PARSE *alloc_string(TOK_OBJ_PARSE *tokens, size_t lenght)
{
  tokens->obj.array[tokens->obj.x] = (char*)malloc((lenght + 1) * sizeof(char));
  if(tokens->obj.array[tokens->obj.x] == NULL) {
	fprintf(stderr, "error: allocate strin value\n");
	exit(1);
  }
  tokens->obj.str_count++;
  return tokens;
}

TOK_OBJ_PARSE *resize_tok_obj(TOK_OBJ_PARSE *tokens, size_t diff)
{
  tokens->obj.array[tokens->obj.x] = (char*)realloc(tokens->obj.array, diff * sizeof(char));
  if(tokens->obj.array[tokens->obj.x] == NULL){
	fprintf(stderr, "realloc error\n");
        return NULL;
  }
  return tokens;
}

void init_obj(TOK_OBJ_PARSE *tokens)
{
  tokens->obj.x = 0;
  tokens->obj.str_count = 0;
}

int parser_json(char *json, TOK_OBJ_PARSE *tokens)
{
  size_t json_lenght = strlen(json);
  
  for(size_t i = 0; i < json_lenght; i++) {
	switch(*json){
	case '{': 
	  tokens->obj.type = JS_TYPE_KEY;
	  break;
	case ':':
	  tokens->obj.type = JS_TYPE_VALUE;
	  break;
	case '"':
	  if(tokens->obj.type == JS_TYPE_VALUE) {
		char *ch_end = string_hadller(json, tokens);
		json = ch_end;
		break;
	  }else
	    break;
	case ',':
	  tokens->obj.type = JS_TYPE_KEY;
	  break;
	case '}':
	  return 0;
	}
	++json;
  }
  return -1;
}

char*
string_hadller(char *json,
	       TOK_OBJ_PARSE *tokens)
{
  char *tok = json;
  if(tok++ == NULL){
	fprintf(stderr, "error: invalid token\n");
	exit(1);
  }
  ++json;
  const char *start  = json;
  char *end = strchr(start, '"');
  size_t lenght = end - start;
  
  /* printf("lenght value: %ld\n", lenght); */

  char *token_buffer = malloc(sizeof(char) * (lenght + 1));
  if(token_buffer == NULL) {
	fprintf(stderr, "error: string handller\n");
	exit(1);
  }

  /* assert(lenght == sizeof(token_buffer)); */
  strncpy(token_buffer, json, lenght);
  token_buffer[lenght] = '\0';

  tokens = alloc_string(tokens, lenght);
  if(tokens->obj.array[tokens->obj.x] == NULL) {
	fprintf(stderr, "erro: allocate string\n");
	exit(1);
  }

  if(lenght > COLUMNS) {
    size_t diff = lenght - COLUMNS;
    fprintf(stderr, "error: string maior que o buffer, a string contem %ld a mais\n", diff);
    tokens = resize_tok_obj(tokens, diff);
    if(tokens->obj.array[tokens->obj.x] == NULL) {
      fprintf(stderr, "error: when realloc string lenght\n");
      exit(1);
    }
    printf("%ld bytes foram allocados\n", diff);
  }
  
  strncpy(tokens->obj.array[tokens->obj.x], token_buffer, lenght);
  tokens->obj.array[tokens->obj.x][lenght] = '\0';
  free(token_buffer);
  if(strlen(tokens->obj.array[tokens->obj.x]) < 1) {
	exit(1);
  }
  /* printf("token: %s\n", tokens->array[tokens->x]); */
  
  tokens->obj.x++;
  tokens->obj.type = JS_TYPE_KEY;
  return end;
}

void destroy_strings(TOK_OBJ_PARSE *tokens)
{
  if(tokens->obj.str_count > 0) {
    for(int i = 0; i <= tokens->obj.str_count; i++){
      free(tokens->obj.array[i]);
    }
    destroy_object(tokens);
  }
}

void destroy_object(TOK_OBJ_PARSE *tokens)
{
  free(tokens);
}
