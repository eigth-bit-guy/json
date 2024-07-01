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

JSTOK_T*
new_jstok_t()
{
  return (JSTOK_T*)malloc(sizeof(JSTOK_T));
}

JSTOK_T*
parser_json(char *json, JSTOK_PARSE *tok_parse,
					            JSTOK_T *jstok_t_object)
{
  int x = 0;
  char token_buffer[100];
  size_t json_size = strlen(json);
  printf("json size: %d\n", json_size);
  char *c = json;
  
  for(size_t i = 0; i <= json_size; i++){
	switch(*c){
	case '{':
	  tok_parse->type = JS_TYPE_KEY;
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
  //print tokens
  for(int z = 0; z <= 1; ++z){
	printf("Tokens: %s\n", jstok_t_object->tokens[z]);
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
  
  return tok_parse->end;
}

//TODO: add dynamic lines for json tokens
void
init_array_of_tokens(char** tokens, int lines)
{
  tokens = (char**)malloc(lines * sizeof(char));
  if(tokens == NULL) {
	fprintf(stderr, "error: token alocation memory\n");
	exit(1);
  }
}

void
insert_token_on_array(size_t token_lenght, char **tokens,
						                            int lines)
{
  for(int i = 0; i != lines; i++) {
	tokens[i] = (char*)malloc((token_lenght + 1) * sizeof(char));
	if(tokens[i] == NULL) {
	  fprintf(stderr, "error: memory allocation failed\n");
	  exit(1);
	}
  }

  
}
