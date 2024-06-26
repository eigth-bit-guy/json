#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#include "..\\include\\libjson.h"

int parser_json(char *json, jstok_t *tok)
{
  int json_size = (int)strlen(json);
  printf("json size: %d\n", json_size);
  char *c = json;
  
  for(int i = 0; i != json_size; i++){
	switch(*c){
	case '{':
	  printf("key\n");
	  tok->type = JS_TYPE_KEY;
	  break;
	case '"':
	  string_hadller(c, tok);
	  tok->type = JS_TYPE_KEY;
	  break;
	case ':':
	  printf("column\n");
	  tok->type = JS_TYPE_VALUE;
	  break;
	case ',':
	  printf("virugla\n");
	  tok->type = JS_TYPE_KEY;
	  break;
	case '}':
	  printf("final\n");
	  return 0; //json final
	  break;
	}
	c++;
  }
  return 0;
}

int string_hadller(char *js_ch, jstok_t *tok)
{
  int i = 0;
  js_ch++;
  const char* start = js_ch;
  char *end = strchr(js_ch, '"');
  size_t len = end - start;
  get_string_from_json(tok, js_ch, len, i);
  *js_ch = end + 1; 
  
  i++;
  return 1;
}

int get_string_from_json(jstok_t *tok, char *json, size_t len, int i)
{
  char token_buffer[20];
  strncpy(token_buffer, json, len);
  token_buffer[len] = '\0';
  printf("tokens: %s\n", token_buffer);
  
  return 1;
}
