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

#define INITIAL_LINES 8
#define MAX_STRING_LEN 15

JSTOK_T*
new_jstok_t()
{
  return (JSTOK_T*)malloc(sizeof(JSTOK_T));
}

<<<<<<< HEAD
int parser_simple_json(char **json, tree_data_json *object)
{
  for(size_t i = 0; i < object->json_lenght; i++) {
	switch(**json){
	case '{': 
	  object->type = LIB_JSON_TYPE_KEY;
	  break;
	case ':':
	  object->type = LIB_JSON_TYPE_VALUE;
=======
JSTOK_T*
parser_json(char *json, JSTOK_PARSE *tok_parse,
			JSTOK_T *jstok_t_object)
{
  int x = 0;
  char token_buffer[100];
  size_t json_size = strlen(json);
  printf("json size: %d\n", json_size);
  char *c = json;
  
  init_array_of_tokens(jstok_t_object->tokens);
  
  for(size_t i = 0; i <= json_size; i++){
	switch(*c){
	case '{':
	  tok_parse->type = JS_TYPE_KEY;
>>>>>>> refatoracao_jsonlib
	  break;
	case '"':
	  if(tok_parse->type == JS_TYPE_VALUE) {
		c++;
		char *ch_offset = string_hadller(c, tok_parse,
					  token_buffer, jstok_t_object, x);
		c = ch_offset;
		break;
	  }else if(tok_parse->type == JS_TYPE_KEY) {
		break;
	  }
	case ':':
	  tok_parse->type = JS_TYPE_VALUE;
	  break;
	case ',':
	  tok_parse->type = JS_TYPE_KEY;
	  break;
	case '}':
	  i = json_size;
	  break;
	}
	c++;
  }

  return jstok_t_object;
}

char*
string_hadller(char *json, JSTOK_PARSE *tok_parse,
			   char *token_buffer, JSTOK_T *tok_t, int x)
{
  char *tok = json;
  if(tok++ == NULL){
	fprintf(stderr, "error: invalid token\n");
	exit(FAILURE);
  }
  
  tok_parse->start = json;
  tok_parse->end = strchr(tok_parse->start, '"');
  tok_parse->lenght = tok_parse->end - tok_parse->start;
	  
  printf("lenght value: %d\n", tok_parse->lenght);

  if(token_buffer == NULL) {
	fprintf(stderr, "error: string handller\n");
	exit(1);
  }

  strncpy(token_buffer, json, tok_parse->lenght);
  token_buffer[tok_parse->lenght] = '\0';

  if(tok_t == NULL) {
	fprintf(stderr, "error: JSTOK_T null\n");
	exit(1);
  }
  
  insert_token_on_array(tok_parse->lenght,
			tok_t->tokens, token_buffer);

  x++;
  tok_t->index_count += 1;
  return tok_parse->end;
}

void
init_array_of_tokens(char** tokens)
{
  tokens = (char**)malloc(INITIAL_LINES * sizeof(char));
  if(tokens == NULL) {
	fprintf(stderr, "error: token alocation\n");
	exit(FAILURE);
  }

  //FIX THAT SHIT
  //malloc faile in i = 7
  for(int i = 0; i <= INITIAL_LINES; i++) {
	tokens[i] = (char*)malloc((MAX_STRING_LEN + 1) * sizeof(char));
	if(tokens[i] == NULL) {
	  fprintf(stderr, "error: allocation memory\n");
	  exit(FAILURE);
	}
  }

}

void
array_push(char *string, char **array)
{
  //TODO: implement
}

void
insert_token_on_array(size_t token_lenght, char **tokens,
					  char *token_buffer)
{
  tokens[0] = token_buffer;
  printf("token value: %s\n", tokens[0]);
}

void
destroy_array_of_tokens(char **tokens, int index)
{
  for(int i = 0; i <= index; i++) {
	free(tokens[i]);
  }
  free(tokens);
}

void
destroy_jstok_t(JSTOK_T *tok_t)
{
  if(tok_t->tokens != NULL) {
	destroy_array_of_tokens(tok_t->tokens, tok_t->index_count);
  }
  free(tok_t);
}
