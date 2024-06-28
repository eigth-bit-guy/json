#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#include "..\\include\\libjson.h"

void clean_tok_parse(jstok_parse *tok_parse)
{
  tok_parse->start = NULL;
  tok_parse->end = NULL;
  tok_parse->lenght = 0;
}

int parser_json(char *json, jstok_parse *tok_parse)
{
  //------------------------------------------
  printf("json value: %s\n", json);
  //------------------------------------------
	
  int json_size = (int)strlen(json);
  printf("json size: %d\n", json_size);
  char *c = json;
  
  for(int i = 0; i != json_size; i++){
	switch(*c){
	case '{':
	  tok_parse->type = JS_TYPE_KEY;
	  break;
	case '"':
	  switch(tok_parse->type) {
	  case JS_TYPE_VALUE:
		clean_tok_parse(tok_parse);
		string_hadller(c, tok_parse);
		break;
	  case JS_TYPE_KEY:
		break;
	  }
	case ':':
	  tok_parse->type = JS_TYPE_VALUE;
	  break;
	case ',':
	  tok_parse->type = JS_TYPE_KEY;
	  break;
	case '}':
	  return 0; //json final
	  break;
	}
	c++;
  }
  return 0;
}

void string_hadller(char *js_ch, jstok_parse *tok_parse)
{
  if(tok_parse->type == JS_TYPE_VALUE){
	int i = 0;
	js_ch++;
    tok_parse->start = js_ch;
    tok_parse->end = strchr(js_ch, '"');
	if(tok_parse->start == NULL || tok_parse->end == NULL) {
	  fprintf(stderr, "Error: string handller\n");
	  exit(1);
	}
    tok_parse->lenght = tok_parse->end - tok_parse->start;
	printf("lenght value: %d\n", tok_parse->lenght);
	get_string_from_json(tok_parse, js_ch, tok_parse->lenght, i);
	i++;
  }
}

int get_string_from_json(jstok_parse *tok_parse, char *json, size_t len, int i)
{
  char token_buffer[len];
  strncpy(token_buffer, json, len);
  token_buffer[len] = '\0';
  printf("tokens: %s\n", token_buffer);
  
  return 1;
}
