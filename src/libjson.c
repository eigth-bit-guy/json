#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#include "..\\include\\libjson.h"

JSTOK_T new_jstok_t()
{
  return (JSTOK_T*)malloc(sizeof(JSTOK_T));
}

JSTOK_T parser_json(char *json, JSTOK_PARSE *tok_parse, JSTOK_T *tok_t)
{
  JSTOK_T jstok_t_object = new_jstok_t();
  char *token_buffer[100];
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
	  case JS_TYPE_VALUE:
		c++;
		char *ch_offset = string_hadller(c, tok_parse, token_buffer);
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

char *string_hadller(char *json, JSTOK_PARSE *tok_parse, char *token_buffer)
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

  strncpy(token_buffer, json, tok_parse->lenght);
  token_buffer[tok_parse->lenght] = '\0';
  printf("tokens: %s\n", token_buffer);
  
  return tok_parse->end;
}
